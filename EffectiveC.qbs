import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac

    files: [
        "main.cpp",
        "type_info_before.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }

    Properties {
        condition: qbs.toolchain.contains('gcc') && qbs.hostOS.contains("osx")
        cpp.cxxFlags: [ "-std=c++11", "-stdlib=libc++" ]
    }
    Properties {
        condition: qbs.toolchain.contains('gcc') && !qbs.hostOS.contains("osx")
        cpp.cxxFlags: [ "-std=c++11" ]
    }
}

