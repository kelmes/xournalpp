/*
 * Xournal++
 *
 * This file is part of the Xournal UnitTests
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#include <config-dev.h>
#include <config-test.h>
#include <CrashHandler.h>
#include <Stacktrace.h>

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <gtk/gtk.h>

#include <iostream>
using std::cout;
using std::endl;

/**
 * Main Entry point for CppUnit Tests
 */
int main(int argc, char* argv[])
{

	//gtk_init(&argc, &argv);

	// init crash handler
	installCrashHandlers();
	if (argc)
	{
		// Filename is needed to get backtracke with filenumbers
		Stacktrace::setExename(argv[0]);
	}

#ifdef DEV_CALL_LOG
	Log::initlog();
#endif

	// Init GTK Display
	//gdk_display_open_default_libgtk_only();

	// Get the top level suite from the registry
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	// Adds the test to the list of test to run
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);

	// Change the default outputter to a compiler error format outputter
	runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));

	// Run the tests.
	bool wasSucessful = runner.run();

	cout << "CppUnit result: " << (wasSucessful ? "succeeded" : "FAILED") << endl;

#ifdef DEV_MEMORY_LEAK_CHECKING
	xoj_momoryleak_printRemainingObjects();
#endif

#ifdef DEV_CALL_LOG
	Log::closelog();
#endif

	// Return error code 1 if the one of test failed.
	return wasSucessful ? 0 : 1;
}
