#include "printer/printer.h"

#include <fmt/core.h>

void Printer::show() const
{
    fmt::println("The show is called!");
}