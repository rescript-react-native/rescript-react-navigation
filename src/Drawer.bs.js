'use strict';

var Interop = require("./Interop");
var Core$ReactNavigation = require("./Core.bs.js");
var Drawer = require("@react-navigation/drawer");

var DrawerNavigationProp = Core$ReactNavigation.NavigationScreenProp;

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
  var string$1 = function (s) {
    return Interop.identity(s);
  };
  var render$1 = function (x) {
    return Interop.identity(x);
  };
  var DrawerLabel = {
    t: t$1,
    string: string$1,
    render: render$1
  };
  var stack = Drawer.createDrawerNavigator();
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
  var make$3 = stack.Group;
  var Group = {
    make: make$3
  };
  return {
          Navigation: Navigation,
          HeaderTitle: HeaderTitle,
          DrawerLabel: DrawerLabel,
          stack: stack,
          ScreenWithCallback: ScreenWithCallback,
          $$Screen: $$Screen,
          $$Navigator: $$Navigator,
          Group: Group
        };
}

exports.DrawerNavigationProp = DrawerNavigationProp;
exports.Make = Make;
/* ./Interop Not a pure module */
