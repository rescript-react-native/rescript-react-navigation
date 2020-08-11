'use strict';

var Interop = require("./Interop");
var Core$ReactNavigation = require("./Core.bs.js");
var Stack = require("@react-navigation/stack");

var TransitionSpec = {};

var StackNavigationScreenProp = Core$ReactNavigation.NavigationScreenProp;

function Make(M) {
  var M$1 = {};
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation = include;
  var t = function (prim) {
    return Interop.identity(prim.VAL);
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
    return Interop.identity(prim.VAL);
  };
  var render$1 = function (x) {
    return Interop.identity(x);
  };
  var $$null = Interop.identity(null);
  var Header = {
    t: t$1,
    render: render$1,
    $$null: $$null
  };
  var stack = Stack.createStackNavigator();
  var make = stack.Screen;
  var ScreenWithCallback = {
    make: make
  };
  var make$1 = stack.Screen;
  var $$Screen = {
    make: make$1
  };
  var make$2 = stack.Navigator;
  var $$Navigator = {
    make: make$2
  };
  return {
          Navigation: Navigation,
          HeaderTitle: HeaderTitle,
          Header: Header,
          stack: stack,
          ScreenWithCallback: ScreenWithCallback,
          $$Screen: $$Screen,
          $$Navigator: $$Navigator
        };
}

var TransitionSpecs = {};

var CardStyleInterpolators = {};

var HeaderStyleInterpolators = {};

var TransitionPresets = {};

exports.TransitionSpec = TransitionSpec;
exports.StackNavigationScreenProp = StackNavigationScreenProp;
exports.Make = Make;
exports.TransitionSpecs = TransitionSpecs;
exports.CardStyleInterpolators = CardStyleInterpolators;
exports.HeaderStyleInterpolators = HeaderStyleInterpolators;
exports.TransitionPresets = TransitionPresets;
/* ./Interop Not a pure module */
