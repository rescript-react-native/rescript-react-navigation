open ReactNative;
type t;

type navigationEventPayload = {
  action: NavigationActions.action,
  context: string,
  [@bs.as "type"]
  _type: string,
  state: NavigationState.t,
  lastState: Js.Nullable.t(NavigationState.t),
};

[@bs.val] [@bs.module "react-navigation"]
external navigationContext: React.Context.t(t) = "NavigationContext";

let useNavigation = () => React.useContext(navigationContext);

[@bs.get] external state: t => NavigationState.t = "state";

[@bs.send] external navigate: (t, string) => unit = "navigate";
[@bs.send]
external navigateWithParams: (t, string, Js.t({..})) => unit = "navigate";
[@bs.send] external goBack: t => unit = "goBack";
[@bs.send] external goBackToRoute: (t, string) => unit = "goBack";
[@bs.send] external dismiss: t => unit = "dismiss";
[@bs.send] external getParam: (t, string) => Js.nullable('a) = "getParam";
[@bs.send] external getParamWithDefault: (t, string, 'a) => 'a = "getParam";
[@bs.send]
external reset: (t, array(NavigationActions.action), int) => unit = "reset";
[@bs.send]
external addListener:
  (
    t,
    [@bs.string] [ | `didBlur | `didFocus | `willBlur | `willFocus],
    navigationEventPayload => unit
  ) =>
  EventSubscription.t =
  "addListener";

[@bs.send] external setParams: (t, Js.t('a)) => unit = "setParams";
// Stack Actions
// TODO: push, replace, ...
[@bs.send] external pop: t => unit = "pop";
[@bs.send] external popN: (t, int) => unit = "pop";
[@bs.send] external popToTop: t => unit = "popToTop";
// Drawer navigator only
[@bs.send] external openDrawer: t => unit = "openDrawer";
[@bs.send] external closeDrawer: t => unit = "closeDrawer";
[@bs.send] external toggleDrawer: t => unit = "toggleDrawer";
