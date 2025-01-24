#pragma once

class Printer
{
public:
    Printer() = default;

    virtual ~Printer() = default;

    void show() const;
};
