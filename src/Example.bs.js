'use strict';

var React = require("react");
var Caml_option = require("rescript/lib/js/caml_option.js");
var ReactNative = require("react-native");
var Stack$ReactNavigation = require("./Stack.bs.js");
var Native = require("@react-navigation/native");

function Example$HomeScreen(props) {
  return React.createElement(ReactNative.Text, {
              children: "Hello Reasonable Person!"
            });
}

var HomeScreen = {
  make: Example$HomeScreen
};

function Example$ModalScreen(props) {
  return React.createElement(ReactNative.Text, {
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
  return React.createElement($$Navigator.make, {
              children: Caml_option.some(React.createElement($$Screen.make, {
                        name: "Home",
                        options: (function (props) {
                            var params = props.route.params;
                            return {
                                    title: params !== undefined ? Caml_option.valFromOption(params).name : "Reason",
                                    headerRight: (function (param) {
                                        return React.createElement(ReactNative.Button, {
                                                    color: "#f00",
                                                    onPress: (function (param) {
                                                        props.navigation.navigate("MyModal");
                                                      }),
                                                    title: "Info"
                                                  });
                                      })
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

function Example$RootStackScreen(props) {
  return React.createElement(Native.NavigationContainer, {
              children: React.createElement($$Navigator$1.make, {
                    screenOptions: (function (param) {
                        return {
                                presentation: "modal"
                              };
                      }),
                    children: Caml_option.some(null)
                  }, React.createElement($$Screen$1.make, {
                        name: "Main",
                        component: Example$MainStackScreen
                      }), React.createElement($$Screen$1.make, {
                        name: "MyModal",
                        children: (function (param) {
                            return React.createElement(Example$ModalScreen, {
                                        navigation: param.navigation,
                                        route: param.route
                                      });
                          })
                      }))
            });
}

var RootStackScreen_Group = include$1.Group;

var RootStackScreen = {
  $$Navigator: $$Navigator$1,
  $$Screen: $$Screen$1,
  Group: RootStackScreen_Group,
  make: Example$RootStackScreen
};

exports.HomeScreen = HomeScreen;
exports.ModalScreen = ModalScreen;
exports.MainStackScreen = MainStackScreen;
exports.RootStackScreen = RootStackScreen;
/* include Not a pure module */
