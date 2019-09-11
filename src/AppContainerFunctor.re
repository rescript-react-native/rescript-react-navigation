// High-level, non-zero-cost bindings to AppContainer.
//
// Usage:
//
// module MyAppContainer =
//   AppContainer.Make({
//     type screenProps = /* my screen props type */;
//     let navigator = /* my root navigator component */;
//   });
//
// <MyAppContainer screenProps /* ... more props ... */ />

module Make = (S: {
                 type screenProps;
                 let navigator: Navigator.t;
               }) => {
  [@bs.module "react-navigation"]
  external make:
    Navigator.t =>
    React.component(AppContainer.appContainerProps(S.screenProps)) =
    "createAppContainer";

  [@bs.obj]
  external makeProps:
    (
      ~persistNavigationState: AppContainer.persistNavigationState=?,
      ~loadNavigationState: AppContainer.loadNavigationState=?,
      ~screenProps: S.screenProps=?,
      ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit=?,
      ~key: string=?,
      unit
    ) =>
    AppContainer.appContainerProps(S.screenProps) =
    "";

  let make = make(S.navigator);
};
