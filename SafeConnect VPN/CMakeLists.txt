# CMakeList.txt: проект CMake для SafeConnect VPN; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "SafeConnect VPN.cpp" "SafeConnect VPN.h" "src/vpn-server/main.c" "src/vpn-server/vpn_manager.c" "src/vpn-server/vpn_manager.h" "src/vpn-server/traffic-analysis/traffic_analyzer.c" "src/vpn-server/traffic-analysis/traffic_analyzer.h" "src/vpn-server/traffic-analysis/monitoring/monitoring.c" "src/vpn-server/traffic-analysis/monitoring/monitoring.h" "src/vpn-server/websocket/websocket_manager.c" "src/vpn-server/websocket/websocket_manager.h" "src/vpn-server/utils/logger.c" "src/vpn-server/utils/logger.h" "src/vpn-server/utils/config_manager.c" "src/vpn-server/utils/config_manager.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
