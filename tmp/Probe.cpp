#include "Probe.h"
  
#include <stdio.h>

Probe Probe::m_PROBE("PROBE");

Probe::Probe(const char* uValue) : Node(uValue) {}

Probe::Probe() {}

void Probe::action() const
{
        printf("This is an action method from node %s\n", type);
}

void Probe::draw() const
{
        printf("This is an %s node!\n", type);
}

Node* Probe::clone() const
{
    return new Probe;
}
