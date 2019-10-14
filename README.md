# `reason-react-navigation`

[![Build Status](https://github.com/reason-react-native/reason-react-navigation/workflows/Build/badge.svg)](https://github.com/reason-react-native/reason-react-navigation/actions)
[![Version](https://img.shields.io/npm/v/reason-react-navigation.svg)](https://www.npmjs.com/reason-react-navigation)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reasonml-community.github.io/reason-react-native/discord/)

[ReasonML](https://reasonml.github.io) /
[BuckleScript](https://bucklescript.github.io) bindings for
[`react-navigation`](https://github.com/react-navigation/react-navigation).

Exposed as `ReactNavigation` module.

`reason-react-navigation` X.y._ means it's compatible with `react-navigation`
X.y._

## Status

⚠️ Work in progress. These bindings are used successfully in several apps, but
are not complete yet and still subject to change.

## Example

An example project is available at
[`navigation-example`](https://github.com/reason-react-native/navigation-example).

## Installation

When
[`react-navigation`](`https://github.com/react-navigation/react-navigation`) is
properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install reason-react-navigation
# or
yarn add reason-react-navigation
```

`reason-react-navigation` should be added to `bs-dependencies` in your
`bsconfig.json`. Something like

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "reason-react-navigation"
  ],
  //...
}
```

## Example

A screen component with dynamic navigation options (Screen1.re):

```reason
open ReactNative;
open ReactNavigation;

[@react.component]
let make = (~navigation, ~screenProps) => {
  <Text> {React.string("Hello world!")} </Text>;
};

make->NavigationOptions.setDynamicNavigationOptions(params => {
  let navigation = params##navigation;
  let navigationOptions = params##navigationOptions;
  let screenProps = params##screenProps;

  /* More properties can be set dynamically based on navigation, navigationOptions or screenProps. */
  NavigationOptions.t(~title="Screen 1", ~headerTintColor="red", ());
});
```

A stack navigator containing this screen (MyStackNavigator.re):

```reason
open ReactNavigation;

let routes = {
  "Screen1": Screen1.make,
  "Screen2": Screen2.make,
  "Screen3": Screen3.make,
};

let navigator = StackNavigator.make(routes);

navigator->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(~gesturesEnabled=false, ()),
);
```

The main React component of the app (App.re):

```reason
open ReactNavigation;

module MyAppContainer =
  AppContainer.Make({
    type screenProps = {. "someProp": int};
    let navigator = MyStackNavigator.navigator;
  });

[@react.component]
let make = () => {
  let screenProps = {"someProp": 42};

  <MyAppContainer screenProps />;
};
```

Alternatively (without a functor, but using `React.createElement`):

```reason
open ReactNavigation;

let appContainer = AppContainer.makeAppContainer(MyStackNavigator.navigator);

[@react.component]
let make = () => {
  let screenProps = {"someProp": 42};

  React.createElement(
    appContainer,
    AppContainer.makeProps(~screenProps, ()),
  );
};
```

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Contribute

Read the [contribution guidelines](./CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](./CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.
