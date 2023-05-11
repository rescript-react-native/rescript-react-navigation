

import * as Interop from "./Interop";
import * as Drawer from "@react-navigation/drawer";

var _map = {"left":"left","right":"right"};

function drawerPositionToJs(param) {
  return param;
}

function drawerPositionFromJs(param) {
  return _map[param];
}

var _map$1 = {"front":"front","back":"back","slide":"slide","permanent":"permanent"};

function drawerTypeToJs(param) {
  return param;
}

function drawerTypeFromJs(param) {
  return _map$1[param];
}

var _map$2 = {"slide":"slide","fade":"fade","none":"none"};

function drawerStatusBarAnimationToJs(param) {
  return param;
}

function drawerStatusBarAnimationFromJs(param) {
  return _map$2[param];
}

var _map$3 = {"open_":"open","closed":"closed"};

var _revMap = {"open":"open_","closed":"closed"};

function drawerStatusToJs(param) {
  return _map$3[param];
}

function drawerStatusFromJs(param) {
  return _revMap[param];
}

function adaptNavigatorModule(prim) {
  return Interop.adaptNavigatorModule(prim);
}

function Make($star) {
  return Interop.adaptNavigatorModule(Drawer.createDrawerNavigator());
}

var Navigation = {};

export {
  drawerPositionToJs ,
  drawerPositionFromJs ,
  drawerTypeToJs ,
  drawerTypeFromJs ,
  drawerStatusBarAnimationToJs ,
  drawerStatusBarAnimationFromJs ,
  drawerStatusToJs ,
  drawerStatusFromJs ,
  adaptNavigatorModule ,
  Make ,
  Navigation ,
  
}
/* ./Interop Not a pure module */
