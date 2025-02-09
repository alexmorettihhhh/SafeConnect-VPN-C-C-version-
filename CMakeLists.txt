# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SafeConnect VPN")

# Включите подпроекты.
add_subdirectory ("SafeConnect VPN")
    src/vpn-server/main.c
    src/vpn-server/vpn_manager.c
    src/traffic-analysis/traffic_analyzer.c
    src/monitoring/monitoring.c
    src/websocket/websocket_manager.c
    src/utils/logger.c
    src/utils/config_manager.c
)

target_include_directories(vpn-management
    PRIVATE
    src/vpn-server
    src/traffic-analysis
    src/monitoring
    src/websocket
    src/utils
)