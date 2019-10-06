'use strict';

var Interop = require("./Interop");
var Core$ReactNavigation = require("./Core.bs.js");
var Stack = require("@react-navigation/stack");

function StackNavigationScreenProp(M) {
  var include = Core$ReactNavigation.NavigationScreenProp(M);
  return {
          navigateByKey: include.navigateByKey,
          navigateByName: include.navigateByName
        };
}

function Make(M) {
  var M$1 = { };
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation_navigateByKey = include.navigateByKey;
  var Navigation_navigateByName = include.navigateByName;
  var Navigation = {
    navigateByKey: Navigation_navigateByKey,
    navigateByName: Navigation_navigateByName
  };
  var t = function (prim) {
    return Interop.identity(prim[1]);
  };
  var string = function (s) {
    return Interop.identity(s);
  };
  var render = function (x) {
    return Interop.identity(x);
  };
  var HeaderTitle = {
    t: t,
    string: string,
    render: render
  };
  var t$1 = function (prim) {
    return Interop.identity(prim[1]);
  };
  var render$1 = function (x) {
    return Interop.identity(x);
  };
  var $$null = Interop.identity(null);
  var Header = {
    t: t$1,
    render: render$1,
    null: $$null
  };
  var TransitionSpec = { };
  var stack = Stack.createStackNavigator();
  var make = stack.Screen;
  var $$Screen = {
    make: make
  };
  var make$1 = stack.Navigator;
  var $$Navigator = {
    make: make$1
  };
  return {
          Navigation: Navigation,
          HeaderTitle: HeaderTitle,
          Header: Header,
          TransitionSpec: TransitionSpec,
          stack: stack,
          Screen: $$Screen,
          Navigator: $$Navigator
        };
}

exports.StackNavigationScreenProp = StackNavigationScreenProp;
exports.Make = Make;
/* ./Interop Not a pure module */
