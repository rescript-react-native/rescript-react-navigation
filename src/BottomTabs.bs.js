

import * as Interop from "./Interop";
import * as BottomTabs from "@react-navigation/bottom-tabs";

var _map = {"below_icon":"below-icon","beside_icon":"beside-icon"};

var _revMap = {"below-icon":"below_icon","beside-icon":"beside_icon"};

function tabBarLabelPositionToJs(param) {
  return _map[param];
}

function tabBarLabelPositionFromJs(param) {
  return _revMap[param];
}

var TabBarBadge = {};

function adaptNavigatorModule(prim) {
  return Interop.adaptNavigatorModule(prim);
}

function Make($star) {
  return Interop.adaptNavigatorModule(BottomTabs.createBottomTabNavigator());
}

var Navigation = {};

export {
  tabBarLabelPositionToJs ,
  tabBarLabelPositionFromJs ,
  TabBarBadge ,
  adaptNavigatorModule ,
  Make ,
  Navigation ,
  
}
/* ./Interop Not a pure module */
