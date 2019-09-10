type config;

[@bs.obj]
external config:
  (
    ~mode: [@bs.string] [ | `card | `modal]=?,
    ~headerMode: [@bs.string] [ | `float | `screen | `none]=?,
    ~headerBackTitleVisible: bool=?,
    ~headerTransitionPreset: [@bs.string] [
                               | [@bs.as "fade-in-place"] `fadeInPlace
                               | `uikit
                             ]
                               =?,
    ~headerLayoutPreset: [@bs.string] [ | `left | `center]=?,
    ~cardStyle: ReactNative.Style.t=?,
    ~cardShadowEnabled: bool=?,
    ~cardOverlayEnabled: bool=?,
    // TODO: many more props
    unit
  ) =>
  config =
  "";

[@bs.module "react-navigation-stack"]
external make: Js.t('a) => Navigator.t = "createStackNavigator";

[@bs.module "react-navigation-stack"]
external makeWithConfig: (Js.t('a), config) => Navigator.t =
  "createStackNavigator";
