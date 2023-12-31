-- project version
set_version("1.0.0")

-- set lanaguage standard 
set_languages("cxx17")
set_allowedmodes("debug", "fastest")
set_defaultmode("debug")

-- find package gtest
add_packages("gtest")
add_requires("gtest")

add_includedirs("./include/", "./src")
add_linkdirs("/opt/local/lib")

-- support both debug and release
if is_mode("debug") then
  set_symbols("debug")
  set_optimize("none")
elseif is_mode("fastest") then
  set_optimize("fastest")
  set_strip("all")
end

target("test")
do
  set_kind("binary")
  add_files("./src/*.cpp")

  on_config(function (target) 
    if not target:has_features("cxx_attributes") then
      target:add("defines", "CXX_ATTRIBUTE_DISABLE=1")
    end
  end)
end
