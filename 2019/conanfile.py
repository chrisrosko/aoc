from conans import ConanFile, CMake, tools


class ConanReceipt(ConanFile):
    name = "aoc2019"
    version = "0.0.1"
    url = ""
    author = "Christian Roeskens"
    generators = "cmake"
    description = "<Description of Hello here>"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    build_requires = (
        "boost/1.69.0@conan/stable",
        "gtest/1.8.1@bincrafters/stable",
        "cereal/1.2.2@conan/stable"
    )
