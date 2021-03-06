-- set_strip("debug")
-- set_symbols("debug")
-- set_warnings("all")
set_optimize("fastest")

target("uMsgpack")
    set_kind("static")
    set_targetdir("dist")
    add_files("src/*.c")
    add_includedirs("include", {public = true})
    add_defines("CONFIG_UMSGPACK_DEFAULT_MEMOP", {public = true})

target("ump_test")
    set_kind("binary")
    set_default(false)
    set_targetdir("dist")
    add_deps("uMsgpack")
    add_files("test/src/**.cc")
    add_includedirs("test/include")
    add_ldflags("-Wl,--wrap=malloc", {force=true})
    add_ldflags("-Wl,--wrap=calloc", {force=true})
    add_ldflags("-Wl,--wrap=realloc", {force=true})
    add_ldflags("-Wl,--wrap=free", {force=true})

target("simple")
    set_kind("binary")
    set_default(false)
    set_targetdir("dist")
    add_deps("uMsgpack")
    add_files("example/simple.c")