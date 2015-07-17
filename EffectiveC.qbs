import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac

    files: [
        "alias_declaration.h",
        "auto.h",
        "brace_initialazers.h",
        "const_iterator.h",
        "constexpr.h",
        "delete.h",
        "enums.h",
        "main.cpp",
        "null_ptr.h",
        "pimpl.cpp",
        "pimpl.h",
        "shared_ptr.h",
        "type_deduction.h",
        "type_info_before.h",
        "type_traits.h",
        "unique_ptr.h",
    ]

    cpp.includePaths: ["/home/piekny/development/boost_1_58_0/"]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }

    Properties {
        condition: qbs.toolchain.contains('gcc') && qbs.hostOS.contains("osx")
        cpp.cxxFlags: [ "-std=c++14", "-stdlib=libc++" ]
    }
    Properties {
        condition: qbs.toolchain.contains('gcc') && !qbs.hostOS.contains("osx")
        cpp.cxxFlags: [ "-std=c++14" ]
    }

}

