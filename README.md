# reason-react-navigation

[Reason](https://reasonml.github.io) bindings to
[react-navigation](https://github.com/react-navigation/react-navigation).

## Status

Work in progress. These bindings are used successfully in several apps, but are
not complete yet and still subject to change.

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
  AppContainerFunctor.Make({
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
