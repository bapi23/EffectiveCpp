import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac

    files: [
        "auto.h",
        "brace_initialazers.h",
        "main.cpp",
        "type_deduction.h",
        "type_info_before.h",
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

