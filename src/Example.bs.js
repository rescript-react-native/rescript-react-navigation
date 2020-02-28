'use strict';

var React = require("react");
var ReactNative = require("react-native");
var Stack$ReactNavigation = require("./Stack.bs.js");
var Native = require("@react-navigation/native");

function Example$HomeScreen(Props) {
  Props.navigation;
  Props.route;
  return React.createElement(ReactNative.Text, {
              children: "Hello Reasonable Person!"
            });
}

var HomeScreen = {
  make: Example$HomeScreen
};

function Example$ModalScreen(Props) {
  Props.navigation;
  Props.route;
  return React.createElement(ReactNative.Text, {
              children: "Hello From Modal"
            });
}

var ModalScreen = {
  make: Example$ModalScreen
};

var StakeParams = { };

var include = Stack$ReactNavigation.Make(StakeParams);

var $$Screen = include.$$Screen;

var $$Navigator = include.$$Navigator;

function Example$MainStackScreen(Props) {
  Props.navigation;
  Props.route;
  return React.createElement($$Navigator.make, {
              children: React.createElement($$Screen.make, {
                    name: "Home",
                    options: (function (props) {
                        var match = props.route.params;
                        return {
                                title: match !== undefined ? match.name : "Reason",
                                headerRight: (function (param) {
                                    return React.createElement(ReactNative.Button, {
                                                color: "#f00",
                                                onPress: (function (param) {
                                                    props.navigation.navigate("MyModal");
                                                    return /* () */0;
                                                  }),
                                                title: "Info"
                                              });
                                  })
                              };
                      }),
                    component: Example$HomeScreen
                  })
            });
}

var MainStackScreen_Navigation = include.Navigation;

var MainStackScreen_HeaderTitle = include.HeaderTitle;

var MainStackScreen_Header = include.Header;

var MainStackScreen_stack = include.stack;

var MainStackScreen = {
  StakeParams: StakeParams,
  Navigation: MainStackScreen_Navigation,
  HeaderTitle: MainStackScreen_HeaderTitle,
  Header: MainStackScreen_Header,
  stack: MainStackScreen_stack,
  $$Screen: $$Screen,
  $$Navigator: $$Navigator,
  make: Example$MainStackScreen
};

var include$1 = Stack$ReactNavigation.Make({ });

var $$Screen$1 = include$1.$$Screen;

var $$Navigator$1 = include$1.$$Navigator;

function Example$RootStackScreen(Props) {
  return React.createElement(Native.NavigationContainer, {
              children: React.createElement($$Navigator$1.make, {
                    mode: "modal",
                    headerMode: "none",
                    children: null
                  }, React.createElement($$Screen$1.make, {
                        name: "Main",
                        component: Example$MainStackScreen
                      }), React.createElement($$Screen$1.make, {
                        name: "MyModal",
                        component: Example$ModalScreen
                      }))
            });
}

var RootStackScreen_Navigation = include$1.Navigation;

var RootStackScreen_HeaderTitle = include$1.HeaderTitle;

var RootStackScreen_Header = include$1.Header;

var RootStackScreen_stack = include$1.stack;

var RootStackScreen = {
  Navigation: RootStackScreen_Navigation,
  HeaderTitle: RootStackScreen_HeaderTitle,
  Header: RootStackScreen_Header,
  stack: RootStackScreen_stack,
  $$Screen: $$Screen$1,
  $$Navigator: $$Navigator$1,
  make: Example$RootStackScreen
};

exports.HomeScreen = HomeScreen;
exports.ModalScreen = ModalScreen;
exports.MainStackScreen = MainStackScreen;
exports.RootStackScreen = RootStackScreen;
/* include Not a pure module */
