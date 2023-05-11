

import * as Interop from "./Interop";
import * as MaterialBottomTabs from "@react-navigation/material-bottom-tabs";

var TabBarBadge = {};

function adaptNavigatorModule(prim) {
  return Interop.adaptNavigatorModule(prim);
}

function Make($star) {
  return Interop.adaptNavigatorModule(MaterialBottomTabs.createMaterialBottomTabNavigator());
}

var Navigation = {};

export {
  TabBarBadge ,
  adaptNavigatorModule ,
  Make ,
  Navigation ,
  
}
/* ./Interop Not a pure module */
