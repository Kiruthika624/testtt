properties ([
  buildDiscarder(
    logRotator(artifactDaysToKeepStr: '',
               artifactNumToKeepStr: '',
               daysToKeepStr: '30',
               numToKeepStr: '100')
  )
])

// no 'def' makes the scope global?
targets = [
  "NUCLEO_F429ZI_LWIP4_UPDATE":     ["board": "NUCLEO_F429ZI",           "build": ["toolchains": ["GCC_ARM"],               "bootloader": true,  "ext": "bin", "size": "2048K", "profile": "develop" ], "tests": ["toolchains": ["GCC_ARM"],    "suite": "update.json",            "raas":"https://ruka.mbedcloudtesting.com" ]],
  "K64F_LWIP4_DELTA_UPDATE":        ["board": "K64F",                    "build": ["toolchains": ["GCC_ARM"],               "bootloader": true,  "ext": "bin", "size": "",      "profile": "develop" ], "tests": ["toolchains": ["GCC_ARM"],    "suite": "update.json",            "raas":"https://eeva.mbedcloudtesting.com" ]],
  "K64F_LWIP4_PSA":                 ["board": "K64F",                    "build": ["toolchains": ["ARM"],                   "bootloader": true,  "ext": "bin", "size": "",      "profile": "develop" ], "tests": ["toolchains": ["ARM"],        "suite": "cloud-minimal-1.2.json", "raas":"https://eeva.mbedcloudtesting.com" ]],
  "K64F_LWIP4_UDP":                 ["board": "K64F",                    "build": ["toolchains": ["GCC_ARM"],               "bootloader": true,  "ext": "bin", "size": "",      "profile": "develop" ], "tests": ["toolchains": ["GCC_ARM"],    "suite": "cloud-minimal-1.2.json", "raas":"https://eeva.mbedcloudtesting.com" ]],
  "K64F_WIFI4":                     ["board": "K64F",                    "build": ["toolchains": ["ARM"],                   "bootloader": true,  "ext": "bin", "size": "",      "profile": "develop" ], "tests": ["toolchains": ["ARM"],        "suite": "cloud-light-1.2.json",   "raas":"https://ruka.mbedcloudtesting.com" ]],
  "K66F_LWIP4_UPDATE":              ["board": "K66F",                    "build": ["toolchains": ["GCC_ARM"],               "bootloader": true,  "ext": "bin", "size": "2048K", "profile": "develop" ], "tests": ["toolchains": ["GCC_ARM"],    "suite": "update.json",            "raas":"https://ruka.mbedcloudtesting.com" ]],
  "K66F_LWIP4_PSA":                 ["board": "K66F",                    "build": ["toolchains": ["ARM"],                   "bootloader": true,  "ext": "bin", "size": "2048K", "profile": "develop" ], "tests": ["toolchains": ["ARM"],        "suite": "cloud-minimal-1.2.json", "raas":"https://ruka.mbedcloudtesting.com" ]],
  "NUCLEO_F411RE_WIFI4":            ["board": "NUCLEO_F411RE",           "build": ["toolchains": ["ARM"],                   "bootloader": true,  "ext": "bin", "size": "",      "profile": "develop" ], "tests": ["toolchains": ["ARM"],        "suite": "cloud-minimal-1.2.json", "raas":"https://ruka.mbedcloudtesting.com" ]],
  "NUCLEO_F429ZI_WISUN_UDP":        ["board": "NUCLEO_F429ZI",           "build": ["toolchains": ["GCC_ARM"],               "bootloader": true,  "ext": "bin", "size": "2048K", "profile": "develop" ], "tests": ["toolchains": [],             "suite": "cloud-minimal-1.2.json", "raas":"https://rauni.mbedcloudtesting.com" ]],
  "Linux":                          ["board": "Linux",                   "build": ["toolchains": ["GCC_ARM"],               "bootloader": false, "ext": "" ],    "tests": ["toolchains": ["GCC_ARM"],    "suite": "cloud-light-1.2.json",   "raas":""                                  ]],
  "Linux_PSA":                      ["board": "Linux",                   "build": ["toolchains": ["GCC_ARM"],               "bootloader": false, "ext": "" ],    "tests": ["toolchains": ["GCC_ARM"],    "suite": "cloud-light-1.2.json",   "raas":""                                  ]],
  "Linux_CLIENT_ONLY":              ["board": "Linux",                   "build": ["toolchains": ["GCC_ARM"],               "bootloader": false, "ext": "" ],    "tests": ["toolchains": [],             "suite": "",                       "raas":""                                  ]],
  "FreeRTOS":                       ["board": "FreeRTOS",                "build": ["toolchains": ["GCC_ARM"],               "bootloader": false, "ext": "" ],    "tests": ["toolchains": ["GCC_ARM"],    "suite": "cloud-light-1.2.json",   "raas":"https://sari.mbedcloudtesting.com" ]],
  "RDA8908":                        ["board": "RDA8908",                 "build": ["toolchains": ["SXOS"],                  "bootloader": false, "ext": "" ],    "tests": ["toolchains": ["SXOS"],       "suite": "cloud-sxos.json",        "raas":"https://irma.mbedcloudtesting.com"]]
]

API_KEY = ""
BINARY_FN = "mbed-client-testapp"
random = new Random();

// Production parameters
ADDRESS="https://api.us-east-1.mbedcloud.com"
ENV_CFG = "client-ci-cloud/env_cfg_production.json"
CERTIFICATE01 = "client-ci-cloud/mbed_cloud_dev_credentials_production-01.c"
CERTIFICATE02 = "client-ci-cloud/mbed_cloud_dev_credentials_production-02.c"
CERTIFICATE03 = "client-ci-cloud/mbed_cloud_dev_credentials_production-03.c"
CERTIFICATE04 = "client-ci-cloud/mbed_cloud_dev_credentials_production-04.c"
CERTIFICATE05 = "client-ci-cloud/mbed_cloud_dev_credentials_production-05.c"
CERTIFICATE06 = "client-ci-cloud/mbed_cloud_dev_credentials_production-06.c"
CERTIFICATE_NAME = "mbed_cloud_dev_credentials.c"

// OS2 parameters
//ADDRESS="https://api-os2.mbedcloudstaging.net"
//ENV_CFG = "cloud-client/env_cfg_os2.json"
//CERTIFICATE01 = "cloud-client/mbed_cloud_dev_credentials_os2-01.c"
//CERTIFICATE02 = "cloud-client/mbed_cloud_dev_credentials_os2-02.c"
//CERTIFICATE03 = "cloud-client/mbed_cloud_dev_credentials_os2-03.c"
//CERTIFICATE04 = "cloud-client/mbed_cloud_dev_credentials_os2-04.c"
//CERTIFICATE05 = "cloud-client/mbed_cloud_dev_credentials_os2-05.c"
//CERTIFICATE06 = "cloud-client/mbed_cloud_dev_credentials_os2-06.c"

WIFI_SSID="systest"
WIFI_PASSWORD="RaaSysT35T"
RAAS_TIMEOUT = 1600

MBED_CLIENT_CI_SCRIPTS = "master"

sxos_builder_docker_image = "853142832404.dkr.ecr.eu-west-1.amazonaws.com/sxros-builder:latest"

// 4\n = target '8908a_nb_modem_p4'
// \n = release(1)/debug(0) default: debug
// \n = build usrgen yes(1)/no(0) default: no
// \n = with svn yes(1)/no(0) default: no
// \n = with git yes(1)/no(0) default: no
rda8908_build_config = "4\\n\\n\\n\\n\\n"

// Map toolchains to compiler labels on Jenkins
def toolchains = [
  ARM: "armcc",
  IAR: "iar_arm",
  GCC_ARM: "arm-none-eabi-gcc",
  SXOS: "linux"
  ]

// Initial maps for parallel build steps
def prepareStepsForParallel = [:]
def buildStepsForParallel = [:]
def testStepsForParallel = [:]

for (target in targets.keySet()) {
    for(toolchain_key in targets[target]["build"]["toolchains"]) {
        def stepName = "${target} ${toolchain_key}"
        echo "Include for build: ${target} ${toolchain_key}"
        buildStepsForParallel[stepName] = buildStep(target, toolchains[toolchain_key], toolchain_key)
    }
    buildStepsForParallel.failFast = false
}

for (target in targets.keySet()) {
    for(toolchain_key in targets[target]["tests"]["toolchains"]) {
        def stepName = "${target} ${toolchain_key}"
        echo "Include for test: ${target} ${toolchain_key}"
        testStepsForParallel[stepName] = testStep(target, toolchain_key)
    }
}

for (target in targets.keySet()) {

    if(targets[target]["build"]["toolchains"]) {
        if ("SXOS" in targets[target]["build"]["toolchains"] && !("prepare SXOS" in prepareStepsForParallel)) {
            echo "Include SXOS prepare step."
            prepareStepsForParallel["prepare SXOS"] = prepareStep("SXOS")
        }
        else if (!("prepare BUILD" in prepareStepsForParallel)) {
            echo "Include BUILD prepare step."
            prepareStepsForParallel["prepare BUILD"] = prepareStep("BUILD")
        }
    }
    if (targets[target]["tests"]["toolchains"] && !("prepare TESTS" in prepareStepsForParallel)) {
        echo "Include TESTS prepare step."
        prepareStepsForParallel["prepare TESTS"] = prepareStep("TESTS")
    }
    prepareStepsForParallel.failFast = false
}

// Actually run the steps in parallel - parallel takes a map as an argument, hence the above.
timestamps {
    stage("Prepare") { parallel prepareStepsForParallel }
    stage("Build")   { parallel buildStepsForParallel }
    stage("Test")    { parallel testStepsForParallel }
}

// Create prepare steps for parallel execution
def prepareStep(type) {
    return {
        stage ("Prepare_${type}") {
            node ("linux") {
                deleteDir()

                if(type == "SXOS") {
                    dir("mbed-client-ci-scripts") {
                        git url:"git@github.com:ARMmbed/mbed-client-ci-scripts.git", branch: "${MBED_CLIENT_CI_SCRIPTS}", shallow: true
                    }
                    dir("sdk") {
                        git url: "git@github.com:ARMmbed/unisoc-sdk.git", branch: "unisoc-v8p2.1-band3,20", shallow: true
                    }
                }
                else if(type == "BUILD") {
                    dir("mbed-client-ci-scripts") {
                        git url:"git@github.com:ARMmbed/mbed-client-ci-scripts.git", branch: "${MBED_CLIENT_CI_SCRIPTS}", shallow: true
                    }
                    dir("mbed-client-testapp") {
                        sh "mbed --version"
                        git url: "git@github.com:ARMmbed/mbed-client-testapp.git", shallow:true
                        // First deploy all the libraries
                        sh "mbed cache"
                        deployWithRetry()
                        // Change mbed-client-pal to PR-head
                        dir("mbed-cloud-client/mbed-client-pal") {
                            checkout scm
                        }

                        sh "git clone -b v1.5.2 git@github.com:ARMmbed/manifest-tool.git"
                        sh "mbed ls"
                    }
                }
                else if(type == "TESTS") {
                    dir("mbed-clitest") {
                        checkout scm: [$class: 'GitSCM', userRemoteConfigs: [[url: "git@github.com:ARMmbed/mbed-clitest.git"]], branches: [[name: "${CLOUD_CLIENT_TEAM_CLITEST}"]]],poll: false
                    }
                    dir("mbed-clitest/mbed-client-ci-scripts") {
                        checkout scm: [$class: 'GitSCM', userRemoteConfigs: [[url: "git@github.com:ARMmbed/mbed-client-ci-scripts.git"]], branches: [[name: "${MBED_CLIENT_CI_SCRIPTS}"]]],poll: false
                    }
                    dir("mbed-clitest/testcases/mbed-clitest-mbed-client") {
                        git url:"git@github.com:ARMmbed/mbed-clitest-mbed-client.git", shallow: true
                    }
                }
                execute("tar czf prepared_${type}.tar.gz --exclude-vcs *")
                execute("ls -la")
                stash name: "prepared_${type}", includes: "prepared_${type}.tar.gz", useDefaultExcludes: false
            }
        }
    }
}


//Create build steps for parallel execution
def buildStep(target, compilerLabel, toolchain) {
    return {
        stage ("Build_${target}_${toolchain}") {
            def config_file = "mbed_app.json"

            node ("${compilerLabel}") {
                deleteDir()

                if(toolchain == "SXOS") {

                    sh "\$(aws ecr get-login --no-include-email) && docker pull $sxos_builder_docker_image"

                    unstash "prepared_SXOS"
                    execute("tar xzf prepared_SXOS.tar.gz")

                    dir("mbed-client-ci-scripts") {
                        sh "cp ${ENV_CFG} env_cfg.json"
                        API_KEY = sh(script: 'cat env_cfg.json | python -c "import sys, json; print json.load(sys.stdin)[\'extApps\'][\'Connector\'][\'token\']"', returnStdout: true)
                        API_KEY = API_KEY.replaceAll("(\\r|\\n)", "");
                    }

                    dir("sdk") {
                        // Setup testapp under soft
                        dir("soft") {

                            unstash "prepared_BUILD"
                            execute("tar xzf prepared_BUILD.tar.gz")

                            dir("mbed-client-testapp") {
                                sh "cp ../../../mbed-client-ci-scripts/${CERTIFICATE04} mbed_cloud_dev_credentials.c"
                            }
                        }

                        // choose config
                        if(targets[target]["board"] == "RDA8908") {
                            build_config = rda8908_build_config
                            binary = "8908a_nb_modem_p4_test_debug/merge_8908a_nb_modem_p4_test_debug_flash.lod"
                        }
                        else {
                            error "No config to build board: ${targets[target]["board"]}"
                        }

                        // run build cmd
                        sh "docker run --rm -i -e LOCAL_USER_ID=`id -u \${USER}` -v \"`pwd`\":/mnt/host $sxos_builder_docker_image 'printf \"$build_config\" > /tmp/conf; cat /tmp/conf; . env/launch.sh < /tmp/conf; echo \\\$PATH; ctmake -C toolpool/blfota; ctmake dbmerge EXTERNAL_APP_FOLDER=mbed-client-testapp DISABLE_DEFAULT_PRINTF=1 MBEDTLS_USER_CONFIG=mbed-client-testapp/mbed-cloud-client/mbed-client-pal/Configs/mbedTLS/mbedTLSConfig_SXOS_SW_TRNG.h'"
                        // stash binary for tests to use
                        sh "cp soft/hex/$binary testapp.lod"
                        stash includes: 'testapp.lod', name: "testapp_${target}"
                    }
                } else {

                unstash "prepared_BUILD"
                execute("tar xzf prepared_BUILD.tar.gz")

                dir("mbed-client-ci-scripts") {
                    sh "cp ${ENV_CFG} env_cfg.json"
                    API_KEY = sh(script: 'cat env_cfg.json | python -c "import sys, json; print json.load(sys.stdin)[\'extApps\'][\'Connector\'][\'token\']"', returnStdout: true)
                    API_KEY = API_KEY.replaceAll("(\\r|\\n)", "");
                }

                dir("mbed-client-testapp") {
                    sh "mbed -h"
                    def BOARD=""

                    if(targets[target]["board"] == "FreeRTOS") {
                        sh "cp ../mbed-client-ci-scripts/${CERTIFICATE01} ./${CERTIFICATE_NAME}"
                    } else if((targets[target]["board"] == "Linux") || ("${target}" == "K64F_LWIP4_UPDATE")) {
                        sh "cp ../mbed-client-ci-scripts/${CERTIFICATE02} ./${CERTIFICATE_NAME}"
                    } else if("${target}" ==~ /(.*)K64F_LWIP4(.*)/ ) {
                        sh "cp ../mbed-client-ci-scripts/${CERTIFICATE03} ./${CERTIFICATE_NAME}"
                    } else if("${target}" ==~ /(.*)K64F_WIFI4(.*)/ ) {
                        sh "cp ../mbed-client-ci-scripts/${CERTIFICATE04} ./${CERTIFICATE_NAME}"
                    } else if("${target}" ==~ /(.*)K64F(.*)/ ) {
                        sh "cp ../mbed-client-ci-scripts/${CERTIFICATE05} ./${CERTIFICATE_NAME}"
                    } else {
                        sh "cp ../mbed-client-ci-scripts/${CERTIFICATE06} ./${CERTIFICATE_NAME}"
                    }

                    if(targets[target]["board"] == "Linux") {
                        // Test pal-platform with both python2 and python3
                        if("${target}" ==~ /(.*)PSA(.*)/ ) {
                            sh "python3 pal-platform/pal-platform.py -v deploy --target=x86_x64_NativeLinux_mbedtls generate"
                        } else {
                            sh "python2 pal-platform/pal-platform.py -v deploy --target=x86_x64_NativeLinux_mbedtls generate"
                        }
                        dir("__x86_x64_NativeLinux_mbedtls") {
                            if("${target}" ==~ /(.*)PSA(.*)/ ) {
                                sh "cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./../pal-platform/Toolchain/GCC/GCC.cmake -DEXTERNAL_DEFINE_FILE=./../define_linux_psa.txt"
                            } else {
                                sh "cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./../pal-platform/Toolchain/GCC/GCC.cmake -DEXTERNAL_DEFINE_FILE=./../define.txt"
                            }
                            sh "make"
                            stash includes: "**/mbedClientTestapp.elf", name: "mbedClientTestapp.elf"
                            step([$class: 'ArtifactArchiver', artifacts: '**/mbedClientTestapp.elf', fingerprint: true])
                        }
                    } else if(targets[target]["board"] == "Linux_CLIENT_ONLY") {
                        sh "python pal-platform/pal-platform.py -v deploy --target=x86_x64_NativeLinux_mbedtls generate"
                        dir("__x86_x64_NativeLinux_mbedtls") {
                            sh "cmake -G 'Unix Makefiles' -DCLIENT_ONLY=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./../pal-platform/Toolchain/GCC/GCC.cmake -DEXTERNAL_DEFINE_FILE=./../define.txt"
                            sh "make"
                            stash includes: "**/mbedClientTestapp.elf", name: "mbedClientTestapp.elf"
                            step([$class: 'ArtifactArchiver', artifacts: '**/mbedClientTestapp.elf', fingerprint: true])
                        }
                    } else if(targets[target]["board"] == "FreeRTOS") {
                        def test = sh (script: "find /usr -name 'arm-none-eabi-gcc'",
                                                        returnStdout: true)

                        sh "python pal-platform/pal-platform.py -v deploy --target=K64F_FreeRTOS_mbedtls generate"
                        withEnv(["ARMGCC_DIR=/usr/local/gcc-arm-none-eabi-6-2017-q1-update"]) {
                            dir("__K64F_FreeRTOS_mbedtls") {
                                sh "cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./../pal-platform/Toolchain/ARMGCC/ARMGCC.cmake -DEXTERNAL_DEFINE_FILE=./../define_freeRTOS.txt"
                                sh "make"
                                stash includes: "**/mbedClientTestapp.bin", name: "mbedClientTestapp.bin"
                                step([$class: 'ArtifactArchiver', artifacts: "**/mbedClientTestapp.bin", fingerprint: true])
                            }
                        }
                    // Rest will be hardware targets with mbed OS
                    } else {

                        BOARD = targets[target]["board"]

                        // Special case with the UDP simple test
                        if("${target}" ==~ /(.*)_UDP(.*)/ ) {
                            sh "sed -i 's/MBED_CLOUD_CLIENT_TRANSPORT_MODE_TCP/MBED_CLOUD_CLIENT_TRANSPORT_MODE_UDP/' mbed-client-testapp/mbed_cloud_client_user_config.h"
                        }
                        if("${target}" ==~ /(.*)LWIP4_PSA(.*)/ ) {
                            echo "Handling LWIP4 PSA"
                            sh "cp configs-psa/eth_v4.json mbed_app.json"
                        } else if("${target}" ==~ /(.*)LWIP4(.*)/ ) {
                            echo "Handling LWIP4"
                        } else if("${target}" ==~ /(.*)WIFI4_PSA(.*)/ ) {
                            echo "Handling WIFI4 for PSA"
                            sh "cp configs-psa/wifi.json mbed_app.json"
                            sh "sed -i 's/SSID/$WIFI_SSID/' mbed_app.json"
                            sh "sed -i 's/Password/$WIFI_PASSWORD/' mbed_app.json"
                        } else if("${target}" ==~ /(.*)WIFI4(.*)/ ) {
                            echo "Handling WIFI4"
                            sh "sed -i 's/SSID/$WIFI_SSID/' mbed_app.json"
                            sh "sed -i 's/Password/$WIFI_PASSWORD/' mbed_app.json"
                        } else if("${target}" ==~ /(.*)WISUN(.*)/ ) {
                            echo "Handling WISUN"
                            sh "cat configs/mesh_wisun.json | jq --arg WISUN_NETWORK_NAME \"\\\"ARM-WS-LAB-NWK\\\"\" '.target_overrides.\"*\".\"mbed-mesh-api.wisun-network-name\"=\$WISUN_NETWORK_NAME' > mbed_app.json"
                        } else {
                            error "Unsupported target: ${target}"
                        }
                        if(("${target}" ==~ "(.)*UPDATE(.)*")) {
                            sh "./manifest-tool/bin/manifest-tool init -d \"test.arm.com\" -m \"mbed-client-testapp-pr\" --force -q"
                        }

                        if(("${target}" ==~ "(.)*DELTA_UPDATE(.)*")) {
                            echo "THIS IS DELTA UPDATE lets build bsdiff"
                            sh "ls"
                            dir("delta-tool"){
                                sh "ls"
                                dir("bsdiff"){
                                    sh "ls"
                                    sh "make bsdiff"
                                    echo "bsdiff build done"
                                }
                            }
                        }

                        def EXT = targets[target]["build"]["ext"]
                        def PROFILE = targets[target]["build"]["profile"]
                        def APP_FN = "BUILD/${BOARD}/${toolchain}/${BINARY_FN}.${EXT}"
                        def UPDATE_FN = "BUILD/${BOARD}/${toolchain}/${BINARY_FN}_update.bin"
                        def FINAL_FN = "${BINARY_FN}.${EXT}"
                        def DELTA_FN = "DELTA.bin"
                        def ORIGINAL_UPDATE_FN = "original_update_image.bin"
                        IMAGEADDRESS="${ADDRESS}/v3/firmware-images"
                        MANIFESTADDRESS="${ADDRESS}/v3/firmware-manifests"

                        sh "cat mbed_app.json"
                        sh "mbed compile -m ${BOARD} -t ${toolchain} -c --profile ${PROFILE} --build BUILD/${BOARD}/${toolchain}"
                        // If defined, truncate the image to the maximum size of the board
                        // This ensures that no pre-existing firmware images remain after flashing the original image (IOTCLT-3364)
                        if(targets[target]["build"]["size"]) {
                            def SIZE = targets[target]["build"]["size"]
                            sh "truncate ${APP_FN} --size ${SIZE}"
                        }

                        sh "cp ${APP_FN} ${FINAL_FN}"
                        sh "cp $UPDATE_FN ${ORIGINAL_UPDATE_FN}"
                        // Stash binary, tests will used it from stash
                        if(targets[target]["tests"]["toolchains"].contains(toolchain)) {
                            stash includes: "${FINAL_FN}", name: "app_${target}_${toolchain}_bin"
                            step([$class: 'ArtifactArchiver', artifacts: "${FINAL_FN}", fingerprint: true])
                            // Handle Update related
                            if(("${target}" ==~ "(.)*UPDATE(.)*")) {


                                sh "mbed compile -m ${BOARD} -t ${toolchain} --profile ${PROFILE} --build BUILD/${BOARD}/${toolchain}"

                                if(("${target}" ==~ "(.)*DELTA_UPDATE(.)*")) {
                                    echo "THIS IS DELTA UPDATE"
                                    sh "cat .manifest_tool.json"
                                    sh "python3 delta-tool/tools/delta-tool.py -s 512 ${ORIGINAL_UPDATE_FN} ${UPDATE_FN} -d ${DELTA_FN} -o delta-manifest.json -i .manifest_tool.json"

                                    stash includes: "**/${DELTA_FN}", name: "${target}_${toolchain}_update_configurations_json"
                                    stash includes: "**/delta-manifest.json", name: "${target}_${toolchain}_update_configurations_json"
                                    echo "delta manifest:"
                                    sh "ls -al"
                                    sh "cat delta-manifest.json"
                                    sh "pwd"
                                    sh "ls -al"
                                    // for some weird reason this will not be visible on console
                                    sh "cat delta-manifest.json"
                                    sh "stat delta-manifest.json"
                                    // just making sure default manifest.json is now also same as delta manifest.
                                    sh "cp delta-manifest.json .manifest_tool.json"
                                    // and for some reason it can't now be displayed either
                                    sh "cat .manifest_tool.json"

                                    // Some hash calculations to check potential problems easier
                                    sh "stat ${DELTA_FN}"
                                    sh "sha256sum < ${DELTA_FN}"

                                    sh "stat ${ORIGINAL_UPDATE_FN}"
                                    sh "sha256sum < ${ORIGINAL_UPDATE_FN}"

                                    sh "stat ${UPDATE_FN}"
                                    sh "sha256sum < ${UPDATE_FN}"

                                    sh "stat ${FINAL_FN}"
                                    sh "sha256sum < ${FINAL_FN}"

                                    // had some issues using delta.bin directly so lets copy original to save and use delta with that name
                                    sh "cp ${UPDATE_FN} updateBackup.bin"
                                    sh "cp ${DELTA_FN} ${UPDATE_FN}"
                                }

                                echo "Uploading new binary to cloud"

                                int randomNumber = random.nextInt(100000);
                                def RANDOM_NAME="${UPDATE_FN}.${randomNumber}"
                                def UPLOAD_URI=sh(script: "curl -v -H \"Authorization: Bearer ${API_KEY}\" -F \"name=${RANDOM_NAME}\" -F \"datafile=@${UPDATE_FN}\" \"${IMAGEADDRESS}\" | python2 -c \"import sys, json; print json.load(sys.stdin)['datafile']\"", returnStdout: true)
                                UPLOAD_URI = UPLOAD_URI.replaceAll("(\\r|\\n)", "");

                                if(("${target}" ==~ "(.)*DELTA_UPDATE(.)*")) {
                                    // lets return the backup of the actual new update image, it was delta just during upload 
                                    sh "cp updateBackup.bin ${UPDATE_FN}"
                                }

                                echo "The name of the file in cloud is ${UPLOAD_URI}"
                                def MANIFEST="${RANDOM_NAME}.manifest"

                                if(("${target}" ==~ "(.)*DELTA_UPDATE(.)*")) {
                                    echo "THIS IS DELTA UPDATE generating delta manifest"
                                    sh "cat delta-manifest.json"
                                    sh "ls -al"
                                    sh(script: "./manifest-tool/bin/manifest-tool create -u ${UPLOAD_URI} -o ${MANIFEST} -i delta-manifest.json --payload-format bsdiff-stream")
                                }else{
                                    sh(script: "./manifest-tool/bin/manifest-tool create -u ${UPLOAD_URI} -p ${UPDATE_FN} -o ${MANIFEST}")
                                }
                                echo "Uploading new manifest to cloud"
                                def OUTPUT_CONFIG="update-configurations.json"
                                sh(script: "curl -v -H \"Authorization: Bearer ${API_KEY}\" -F name=${RANDOM_NAME} -F datafile=@${MANIFEST} ${MANIFESTADDRESS} > ${OUTPUT_CONFIG}")
                                echo "Generated output-config"
                                echo "${OUTPUT_CONFIG}"

                                stash includes: "**/update-configurations.json", name: "${target}_${toolchain}_update_configurations_json"
                                step([$class: 'ArtifactArchiver', artifacts: '**/update-configurations.json', fingerprint: true])
                            }
                        }
                    }
                }
                }
            step([$class: 'WsCleanup'])
            }
        }
    }
}

def testStep(target, toolchain) {
    return {
        stage ("Light suite ${target}_${toolchain}") {
            node ("client-test") {
                deleteDir()
                unstash "prepared_TESTS"
                execute("tar xzf prepared_TESTS.tar.gz")

                env.RAAS_USERNAME = "ci"
                env.RAAS_PASSWORD = "ci"
                EXT = targets[target]["build"]["ext"]
                def FINAL_FN = "${BINARY_FN}.${EXT}"
                def LOG_DIR="${target}_${toolchain}"
                def ADDR=targets[target]["tests"]["raas"]
                def SUITE=targets[target]["tests"]["suite"]
                if(targets[target]["board"] == "Linux") {
                    unstash "mbedClientTestapp.elf"
                    sh "cp Debug/mbedClientTestapp.elf mbed-clitest"
                    dir("mbed-clitest") {
                        sh "python clitest.py --bin ./mbedClientTestapp.elf --log ${LOG_DIR} --suitedir testcases/mbed-clitest-mbed-client/suites --suite ${SUITE} --env_cfg mbed-client-ci-scripts/${ENV_CFG} --type process -v -w --nobuf NOBUF --stop_on_failure"
                    }
                } else if(targets[target]["board"] == "FreeRTOS") {
                    unstash "mbedClientTestapp.bin"
                    sh "cp Debug/mbedClientTestapp.bin mbed-clitest"
                    dir("mbed-clitest") {
                        sh "python clitest.py --raas ${ADDR} --raas_share_allocs --raas_queue --raas_queue_timeout ${RAAS_TIMEOUT} --forceflash_once --bin mbedClientTestapp.bin --log ${LOG_DIR} --suitedir testcases/mbed-clitest-mbed-client/suites --suite ${SUITE} --env_cfg mbed-client-ci-scripts/${ENV_CFG} --type hardware --reset -v -w --nobuf NOBUF --stop_on_failure"
                    }
                } else if(targets[target]["board"] == "RDA8908") {
                    unstash "testapp_${target}"
                    sh "cp testapp.lod mbed-clitest"
                    dir("mbed-clitest") {
                        sh "python clitest.py --raas ${ADDR} --raas_share_allocs --raas_queue --raas_queue_timeout ${RAAS_TIMEOUT} --forceflash_once --bin testapp.lod --log ${LOG_DIR} --suitedir testcases/mbed-clitest-mbed-client/suites/ --suite ${SUITE} --env_cfg mbed-client-ci-scripts/${ENV_CFG} --type hardware -v -w --tc_cfg mbed-client-ci-scripts/configs/tc_UNISOC.json"
                    }
                } else {
                    unstash "app_${target}_${toolchain}_bin"

                    sh "cp ${FINAL_FN} mbed-clitest"
                    dir("mbed-clitest") {
                        if(("${target}" ==~ "(.)*UPDATE(.)*")) {
                            unstash "${target}_${toolchain}_update_configurations_json"
                        }
                        sh "ls -ltr"
                        sh "python clitest.py --raas ${ADDR} --raas_share_allocs --raas_queue --raas_queue_timeout ${RAAS_TIMEOUT} --forceflash_once --bin ${FINAL_FN} --log ${LOG_DIR} --suitedir testcases/mbed-clitest-mbed-client/suites --suite ${SUITE} --env_cfg mbed-client-ci-scripts/${ENV_CFG} --type hardware --reset -v -w --tc_cfg mbed-client-ci-scripts/configs/tc_${target}.json --stop_on_failure"
                    }
                }
                step([$class: 'ArtifactArchiver', artifacts: "mbed-clitest/${LOG_DIR}/**/*", fingerprint: true])
                step([$class: 'JUnitResultArchiver', testResults: "mbed-clitest/${LOG_DIR}/junit.xml"])
                publishHTML(target: [allowMissing: false, alwaysLinkToLastBuild: false, keepAll: false,
                   reportDir: "mbed-clitest/${LOG_DIR}/",
                   reportFiles: 'latest.html',
                   reportName: "Test Results for ${toolchain} with ${target}"])

                //clear provisioned device from the DC
                DEVICE_ID = sh (
                    script: "find . -name bench.Dut.D1.log -type f -exec grep 'EndpointName:' {} \\; | tail -c 33",
                    returnStdout: true
                ).trim()

                sh (
                    script: "curl -X DELETE -H 'Content-Type: application/json' -H 'Authorization: Bearer ${API_KEY}' '${ADDRESS}/v3/devices/${DEVICE_ID}'",
                    returnStdout: true
                )

                // Clean up workarea
                step([$class: 'WsCleanup'])
            }
        }
    }
}

def deployWithRetry() {
    try {
        sh "mbed deploy --protocol ssh"
    } catch (e) {
        echo "First deploy failed, retrying."
        // Wait 10 seconds
        sleep(10)
        sh "mbed deploy --protocol ssh"
    }
}
