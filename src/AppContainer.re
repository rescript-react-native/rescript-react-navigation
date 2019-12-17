// There are two ways to use the AppContainer module.
//
// 1. With React.createElement, zero-cost
// ======================================
//
// open ReactNavigation;
//
// let appContainer = AppContainer.makeAppContainer(MyStackNavigator.navigator);
//
// [@react.component]
// let make = () => {
//   let screenProps = {"someProp": 42};
//
//   React.createElement(
//     appContainer,
//     AppContainer.makeProps(~screenProps, ()),
//   );
// };

type persistNavigationState = NavigationState.t => Js.Promise.t(unit);
type loadNavigationState = unit => Js.Promise.t(option(NavigationState.t));

type appContainerProps('screenProps) = {
  .
  "persistNavigationState": option(persistNavigationState),
  "loadNavigationState": option(loadNavigationState),
  "screenProps": option('screenProps),
  "ref": Js.Nullable.t(NavigationContainer.t) => unit,
};

[@bs.obj]
external makeProps:
  (
    ~persistNavigationState: persistNavigationState=?,
    ~loadNavigationState: loadNavigationState=?,
    ~screenProps: 'screenProps=?,
    ~ref: Js.Nullable.t(NavigationContainer.t) => unit=?,
    ~key: string=?,
    unit
  ) =>
  appContainerProps('screenProps) =
  "";

[@bs.module "react-navigation"]
external makeAppContainer:
  Navigator.t => React.component(appContainerProps('screenProps)) =
  "createAppContainer";

// 2. Without create element, using a functor instead
// ==================================================
//
// open ReactNavigation;
//
// module MyAppContainer =
//   AppContainer.Make({
//     type screenProps = {. "someProp": int};
//     let navigator = MyStackNavigator.navigator;
//   });
//
// [@react.component]
// let make = () => {
//   let screenProps = {"someProp": 42};
//
//   <MyAppContainer screenProps />;
// };

module Make = (S: {
                 type screenProps;
                 let navigator: Navigator.t;
               }) => {
  [@bs.module "react-navigation"]
  external make:
    Navigator.t => React.component(appContainerProps(S.screenProps)) =
    "createAppContainer";

  [@bs.obj]
  external makeProps:
    (
      ~persistNavigationState: persistNavigationState=?,
      ~loadNavigationState: loadNavigationState=?,
      ~screenProps: S.screenProps=?,
      ~ref: Js.Nullable.t(NavigationContainer.t) => unit=?,
      ~key: string=?,
      unit
    ) =>
    appContainerProps(S.screenProps) =
    "";

  let make = make(S.navigator);
};
