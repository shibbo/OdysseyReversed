#include "types.h"
#include "al/util.h"
#include "custom/logger.h"

void basic_function()
{
	log("Display Width: %i", al::getDisplayWidth());
	log("Display Height: %i", al::getDisplayHeight());
}