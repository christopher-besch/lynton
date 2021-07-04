#include "lynton.h"

int main()
{
    Lynton::Log::init();
    Lynton::Log::set_lynton_level(Lynton::LogLevel::Extra);
    log_client_extra("Hello World");
}
