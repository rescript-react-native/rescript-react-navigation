'use strict';

var Js_dict = require("rescript/lib/js/js_dict.js");
var Caml_option = require("rescript/lib/js/caml_option.js");
var ReactNative = require("react-native");
var JsxRuntime = require("react/jsx-runtime");
var Stack$ReactNavigation = require("./Stack.bs.js");
var Native = require("@react-navigation/native");

function Example$HomeScreen(props) {
  return JsxRuntime.jsx(ReactNative.Text, {
              children: "Hello Reasonable Person!"
            });
}

var HomeScreen = {
  make: Example$HomeScreen
};

function Example$ModalScreen(props) {
  return JsxRuntime.jsx(ReactNative.Text, {
              children: "Hello From Modal"
            });
}

var ModalScreen = {
  make: Example$ModalScreen
};

var include = Stack$ReactNavigation.Make({});

var $$Navigator = include.$$Navigator;

var $$Screen = include.$$Screen;

function Example$MainStackScreen(props) {
  return JsxRuntime.jsx($$Navigator.make, {
              children: Caml_option.some(JsxRuntime.jsx($$Screen.make, {
                        name: "Home",
                        options: (function (props) {
                            var params = props.route.params;
                            return {
                                    headerRight: (function (param) {
                                        return JsxRuntime.jsx(ReactNative.Button, {
                                                    color: "#f00",
                                                    onPress: (function (param) {
                                                        props.navigation.navigate("MyModal");
                                                      }),
                                                    title: "Info"
                                                  });
                                      }),
                                    title: params !== undefined ? Caml_option.valFromOption(params).name : "Reason"
                                  };
                          }),
                        component: Example$HomeScreen
                      }))
            });
}

var MainStackScreen_Group = include.Group;

var MainStackScreen = {
  $$Navigator: $$Navigator,
  $$Screen: $$Screen,
  Group: MainStackScreen_Group,
  make: Example$MainStackScreen
};

var include$1 = Stack$ReactNavigation.Make({});

var $$Navigator$1 = include$1.$$Navigator;

var $$Screen$1 = include$1.$$Screen;

var linking_prefixes = ["https://www.example.com"];

var linking_config = {
  initialRouteName: "app",
  screens: Js_dict.fromArray([[
          "app",
          {
            screens: Js_dict.fromArray([
                  [
                    "tab1",
                    {
                      screens: Js_dict.fromArray([[
                              "home",
                              {
                                path: ""
                              }
                            ]])
                    }
                  ],
                  [
                    "tab2",
                    {
                      screens: Js_dict.fromArray([[
                              "config",
                              {
                                path: "/config"
                              }
                            ]])
                    }
                  ]
                ])
          }
        ]])
};

var linking = {
  prefixes: linking_prefixes,
  config: linking_config
};

function Example$RootStackScreen(props) {
  return JsxRuntime.jsx(Native.NavigationContainer, {
              linking: linking,
              children: JsxRuntime.jsxs($$Navigator$1.make, {
                    screenOptions: (function (param) {
                        return {
                                presentation: "modal"
                              };
                      }),
                    children: [
                      JsxRuntime.jsx($$Screen$1.make, {
                            name: "Main",
                            component: Example$MainStackScreen
                          }),
                      JsxRuntime.jsx($$Screen$1.make, {
                            name: "MyModal",
                            children: (function (param) {
                                return JsxRuntime.jsx(Example$ModalScreen, {
                                            navigation: param.navigation,
                                            route: param.route
                                          });
                              })
                          })
                    ]
                  })
            });
}

var RootStackScreen_Group = include$1.Group;

var RootStackScreen = {
  $$Navigator: $$Navigator$1,
  $$Screen: $$Screen$1,
  Group: RootStackScreen_Group,
  linking: linking,
  make: Example$RootStackScreen
};

exports.HomeScreen = HomeScreen;
exports.ModalScreen = ModalScreen;
exports.MainStackScreen = MainStackScreen;
exports.RootStackScreen = RootStackScreen;
/* include Not a pure module */
