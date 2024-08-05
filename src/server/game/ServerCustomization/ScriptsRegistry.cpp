#include "ScriptsRegistry.h"

#include "PermaDeath.h"

void JulMan::RegisterCustomScripts() {
    JulMan::PermaDeath::instance();
}
