if (NOT TARGET retarget)
    add_subdirectory(retarget)
endif ()

if (NOT TARGET GPIO)
    add_subdirectory(GPIO)
endif ()

if (NOT TARGET Timer)
    add_subdirectory(Timer)
endif ()

if (NOT TARGET etl)
    add_subdirectory(etl)
endif ()

if (NOT TARGET DoubleBuffer)
    add_subdirectory(DoubleBuffer)
endif ()

if (NOT TARGET CMSISDSP)
    add_subdirectory(CMSIS-DSP)
endif ()

if (NOT TARGET AD5667)
    add_subdirectory(AD5667)
endif ()

if (NOT TARGET MathUtils)
    add_subdirectory(MathUtils)
endif ()

if (NOT TARGET eigen)
    add_subdirectory(eigen)
endif ()

if (NOT TARGET SignalProcessors)
    add_subdirectory(SignalProcessors)
endif ()

if (NOT TARGET Interpolation)
    add_subdirectory(Interpolation)
endif ()

if (NOT TARGET PeripheralCommunication)
    add_subdirectory(PeripheralCommunication)
endif ()

if (NOT TARGET ControlAlgorithms)
    add_subdirectory(ControlAlgorithms)
endif ()