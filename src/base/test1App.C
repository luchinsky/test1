#include "test1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
test1App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

test1App::test1App(InputParameters parameters) : MooseApp(parameters)
{
  test1App::registerAll(_factory, _action_factory, _syntax);
}

test1App::~test1App() {}

void
test1App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"test1App"});
  Registry::registerActionsTo(af, {"test1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
test1App::registerApps()
{
  registerApp(test1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
test1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test1App::registerAll(f, af, s);
}
extern "C" void
test1App__registerApps()
{
  test1App::registerApps();
}
