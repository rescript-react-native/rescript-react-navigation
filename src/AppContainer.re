// Low-level, zero-cost bindings to AppContainer.
//
// Usage:
//
// let appContainer = AppContainer.makeAppContainer(rootNavigator);
//
// React.createElement(
//   appContainer,
//   AppContainer.makeProps(
//     ~screenProps, /* ... more props ... */
//     (),
//   ),
// );

type persistNavigationState = NavigationState.t => Js.Promise.t(unit);
type loadNavigationState = unit => Js.Promise.t(option(NavigationState.t));

type appContainerProps('screenProps) = {
  .
  "persistNavigationState": option(persistNavigationState),
  "loadNavigationState": option(loadNavigationState),
  "screenProps": option('screenProps),
  "setNavigatorRef": Js.Nullable.t(NavigationContainer.t) => unit,
};

[@bs.obj]
external makeProps:
  (
    ~persistNavigationState: persistNavigationState=?,
    ~loadNavigationState: loadNavigationState=?,
    ~screenProps: 'screenProps=?,
    ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit=?,
    ~key: string=?,
    unit
  ) =>
  appContainerProps('screenProps) =
  "";

[@bs.module "react-navigation"]
external makeAppContainer:
  Navigator.t => React.component(appContainerProps('screenProps)) =
  "createAppContainer";
