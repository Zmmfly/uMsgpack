#include <stdio.h>
#include <string>
#include <list>
#include <mutex>
#include <sys/time.h>

#include "test_add.h"
#include "test_astf.h"
#include "test_get.h"
#include "test_gstf.h"
#include "test_mix.h"
#include "utils/test.h"

std::mutex mem_mtx;
bool mem_guard = false;
bool mem_echo  = false;
typedef struct mem_info
{
    void *ptr;
    size_t size;
    std::string time;
}mem_info;
typedef mem_info* mem_info_t;
std::list<mem_info_t> mem_list;

void mem_guard_start();
void mem_guard_stop();
bool mem_guard_print();
void mem_guard_echo(bool ena);

int main(int argc, char **argv)
{
    mem_guard_start();
    // mem_guard_echo(true);
    utils::test::run_units(t_add_units, t_add_num, false, "add_stmem: ");
    utils::test::run_units(t_get_units, t_get_num, false, "get_stmem: ");
    utils::test::run_units(t_mix_units, t_mix_num, false, "mix_stmem: ");
    utils::test::run_units(t_astf_units, t_astf_num, false, "add_stfil: ");
    utils::test::run_units(t_gstf_units, t_gstf_num, false, "add_gtfil: ");
    mem_guard_stop();
    mem_guard_print();
    return 0;
}

void mem_guard_echo(bool ena)
{
    std::lock_guard<std::mutex> lck(mem_mtx);
    mem_echo = ena;
}

void mem_guard_start()
{
    std::lock_guard<std::mutex> lk(mem_mtx);
    mem_guard = true;
}

void mem_guard_stop()
{
    std::lock_guard<std::mutex> lk(mem_mtx);
    mem_guard = false;
}

bool mem_guard_print()
{
    std::lock_guard<std::mutex> lk(mem_mtx);
    bool leak  = false;
    if (!mem_guard) return leak;
    for (auto it = mem_list.begin(); it != mem_list.end(); it++)
    {
        leak = true;
        printf("%s: %p, %zu\n", (*it)->time.c_str(), (*it)->ptr, (*it)->size);
        delete *it;
        mem_list.erase(it);
    }
    return leak;
}

std::string get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    char buf[128];
    snprintf(buf, 128, "%ld.%ld", tv.tv_sec, tv.tv_usec);
    return buf;
}

extern "C" {

void* __wrap_malloc(size_t size);
void* __wrap_calloc(size_t nmemb, size_t size);
void* __wrap_realloc(void *ptr, size_t size);
void __wrap_free(void* ptr);

void* __real_malloc(size_t size);
void* __real_calloc(size_t nmemb, size_t size);
void* __real_realloc(void *ptr, size_t size);
void __real_free(void* ptr);

}

void* __wrap_malloc(size_t size)
{
    std::lock_guard<std::mutex> lck(mem_mtx);
    void *ptr = __real_malloc(size);
    do{
        if (ptr == nullptr || !mem_guard) break;
        mem_info_t info = new mem_info;
        if (info == nullptr) break;
        info->ptr  = ptr;
        info->size = size;
        info->time = get_time();
        mem_list.push_back(info);
        if (mem_echo) printf("%s: malloc %p, %zu\n", info->time.c_str(), info->ptr, info->size);
    }while(0);
    return ptr;
}

void* __wrap_calloc(size_t nmemb, size_t size)
{
    std::lock_guard<std::mutex> lck(mem_mtx);
    void *ptr = __real_calloc(nmemb, size);
    do{
        if (ptr == nullptr || !mem_guard) break;

        mem_info_t info = new mem_info;
        if (info == nullptr) break;

        info->ptr  = ptr;
        info->size = size * nmemb;
        info->time = get_time();

        mem_list.push_back(info);
        if (mem_echo) printf("%s: calloc %p, %zu\n", info->time.c_str(), info->ptr, info->size);
    }while(0);
    return ptr;
}

void* __wrap_realloc(void *ptr, size_t size)
{
    std::lock_guard<std::mutex> lck(mem_mtx);
    void *ptr_ = __real_realloc(ptr, size);
    if (ptr == nullptr) return nullptr;
    do{
        if (ptr == nullptr || !mem_guard) break;
        for (auto it=mem_list.begin(); it!=mem_list.end(); it++) {
            if ((*it)->ptr == ptr) {
                delete *it;
                mem_list.erase(it);
                break;
            }
        }

        mem_info_t info = new mem_info;
        if (info == nullptr) break;

        info->ptr  = ptr;
        info->size = size;
        info->time = get_time();
        
        mem_list.push_back(info);
        if (mem_echo) printf("%s: realloc %p, %zu, new: %p\n", info->time.c_str(), ptr, info->size, info->ptr);
    }while(0);
    return ptr_;
}

void __wrap_free(void* ptr)
{
    std::lock_guard<std::mutex> lck(mem_mtx);
    if (ptr == nullptr) return;
    do{
        if (!mem_guard) break;
        for (auto it=mem_list.begin(); it!=mem_list.end(); it++) {
            if ((*it)->ptr == ptr) {
                delete *it;
                mem_list.erase(it);
                break;
            }
        }
        if (mem_echo) printf("free %p\n", ptr);
    }while(0);
}
