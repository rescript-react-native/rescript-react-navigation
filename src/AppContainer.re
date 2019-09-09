type persistNavigationState = NavigationState.t => Js.Promise.t(unit);
type loadNavigationState = unit => Js.Promise.t(option(NavigationState.t));

type appContainerProps('screenProps) = {
  .
  "persistNavigationState": option(persistNavigationState),
  "loadNavigationState": option(loadNavigationState),
  "screenProps": option('screenProps),
  "setNavigatorRef": Js.Nullable.t(NavigationContainer.t) => unit,
};

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
      ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit=?,
      ~key: string=?,
      unit
    ) =>
    appContainerProps(S.screenProps) =
    "";

  let make = make(S.navigator);
};
