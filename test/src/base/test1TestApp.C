//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "test1TestApp.h"
#include "test1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
test1TestApp::validParams()
{
  InputParameters params = test1App::validParams();
  return params;
}

test1TestApp::test1TestApp(InputParameters parameters) : MooseApp(parameters)
{
  test1TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

test1TestApp::~test1TestApp() {}

void
test1TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  test1App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"test1TestApp"});
    Registry::registerActionsTo(af, {"test1TestApp"});
  }
}

void
test1TestApp::registerApps()
{
  registerApp(test1App);
  registerApp(test1TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
test1TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test1TestApp::registerAll(f, af, s);
}
extern "C" void
test1TestApp__registerApps()
{
  test1TestApp::registerApps();
}
