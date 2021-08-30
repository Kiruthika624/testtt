# PAL
This is the main repository for the Platform Abstraction Layer (PAL) project.

# Releases

In order to get the latest stable and tested code, please goto [releases](https://github.com/ARMmbed/mbed-client-pal/releases)
and download the required release version - each release has a comment regarding which official mbedOS version was used for 
development and testing.


# General Use Notes

* `pal_init()` API MUST be called before using any other PAL API, calling PAL APIs without 
  initialization PAL can return with initialization error.
* `pal_destroy()` API MUST be called to free any allocated resources by PAL Modules.


# How To Build PAL Tests
## MbedOS

1. Define the environment variable: `MBEDOS_ROOT` to be the father folder of "mbed-os".
2. `cd $(PAL_FOLDER)/Test/`
3. In order to build and run the tests over the platform with ARMGCC toolchain, for example, please run: 

		$ make -f makefile_mbedOS.mk MBEDOS_COMP=GCC_ARM MBEDOS_TARGET=K64F mbedOS_all DEBUG=1

4. In order to see debug prints please send the following flag `DEBUG=1` in compilation command: 

		$ make mbedOS_check DEBUG=1

5. In order to build single module tests please edit `$(PAL_FOLDER)/Test/makefile`
   under mbedOS5.X platform, please change the value of the `TARGET_CONFIGURATION_DEFINES` to the 
   desired module: (Default value is for ALL existing modules)

	Example:
	
		HAS_RTOS --> RTOS module APIs
		HAS_UPDATE --> Update module APIs
		HAS_SOCKET --> Networking module APIs
				
## Non MbedOS Operating systems

Please build PAL tests according to sources and directories written inside $(PAL_FOLDER)/Test/all_tests.mk file
For your $(TARGET_PLATFORM)


# PAL Repository Directory structure
```
├───Docs
├───Examples
├───Source
│   ├───PAL-Impl
│   │   ├───Modules
│   │   │   ├───Crypto
│   │   │   ├───FileSystem
│   │   │   ├───Networking
│   │   │   ├───RTOS
│   │   │   ├───Time
│   │   │   ├───TLS
│   │   │   └───Update
│   │   └───Services-API
│   └───Port
│       ├───Platform-API
│       └───Reference-Impl
│           ├──Generic
│           │   ├──DRBG
│           │   │   └──SOTP
│           │   ├──ROT
│           │   │   └──SOTP
│           │   └──Time
│           │       └──SOTP
│           ├───Lib_Specific
│           │   └───mbedTLS
│           │       ├───Crypto
│           │       └───TLS
│           └───OS_Specific
│               ├───FreeRTOS
│               │   ├───Board_Specific
│               │   │   └───K64F
│               │   ├───FileSystem
│               │   ├───Networking
│               │   │   └───LWIP
│               │   ├───RTOS
│               │   └───Update
│               ├───Linux
│               │   ├───Board_Specific
│               │   │   └───x86_x64
│               │   ├───FileSystem
│               │   ├───Networking
│               │   ├───RTOS
│               │   └───Update
│               └───mbedOS
│                   ├───Board_Specific
│                   │   └───K64F
│                   ├───FileSystem
│                   ├───Networking
│                   ├───RTOS
│                   └───Update
├───Test
│   ├───Conformance
│   ├───Scripts
│   ├───Unitest
│   │   ├───Includes
│   │   ├───PAL_Modules
│   │   │   ├───Crypto
│   │   │   ├───FileSystem
│   │   │   ├───Networking
│   │   │   ├───RTOS
│   │   │   ├───Time
│   │   │   ├───TLS
│   │   │   └───Update
│   │   ├───PlatformBSP
│   │   │   ├───Beaglebone_Linux
│   │   │   ├───Include
│   │   │   ├───MK64F_FreeRTOS
│   │   │   ├───MK64F_mbedOS
│   │   │   └───x86_x64_Linux
│   │   └───TestRunner
│   └───Unity
└───Utils
    └───Scripts
        └───Build-Scripts


```

