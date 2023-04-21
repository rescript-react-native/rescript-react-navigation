// https://reactnavigation.org/docs/native-stack-navigator/

open Core;
open ReactNative;

[@bs.module "react-native-screens"]
external enableScreens: unit => unit = "enableScreens";

[@bs.deriving jsConverter]
type animation = [
  | `default
  | `fade
  | `fade_from_bottom
  | `flip
  | `simple_push
  | `slide_from_bottom
  | `slide_from_right
  | `slide_from_left
  | `none
];

[@bs.deriving jsConverter]
type animationTypeForReplace = [ | `push | `pop];

[@bs.deriving abstract]
type headerBackTitleStyle = {
  [@bs.optional]
  fontFamily: string,
  [@bs.optional]
  fontSize: float,
};

[@bs.deriving jsConverter]
type blurEffect = [
  | `extraLight
  | `light
  | `dark
  | `regular
  | `prominent
  | `systemUltraThinMaterial
  | `systemThinMaterial
  | `systemMaterial
  | `systemThickMaterial
  | `systemChromeMaterial
  | `systemUltraThinMaterialLight
  | `systemThinMaterialLight
  | `systemMaterialLight
  | `systemThickMaterialLight
  | `systemChromeMaterialLight
  | `systemUltraThinMaterialDark
  | `systemThinMaterialDark
  | `systemMaterialDark
  | `systemThickMaterialDark
  | `systemChromeMaterialDark
];

[@bs.deriving abstract]
type headerLargeStyle = {
  [@bs.optional]
  backgroundColor: Color.t,
};

type headerLargeTitleStyle = {
  fontFamily: option(string),
  fontSize: option(float),
  color: option(Color.t),
};

[@bs.deriving abstract]
type headerStyle = {
  [@bs.optional]
  backgroundColor: Color.t,
};

[@bs.deriving abstract]
type headerTitleStyle = {
  [@bs.optional]
  fontFamily: string,
  [@bs.optional]
  fontSize: float,
  [@bs.optional]
  fontWeight: ReactNativeExt.fontWeight,
  [@bs.optional]
  color: Color.t,
};

[@bs.deriving jsConverter]
type presentation = [
  | `card
  | `modal
  | `transparentModal
  | `containedModal
  | `containedTransparentModal
  | `fullScreenModal
  | `formSheet
];

[@bs.deriving jsConverter]
type statusBarStyle = [ | `auto | `inverted | `light | `dark];

[@bs.deriving jsConverter]
type statusBarAnimation = [ | `fade | `none | `slide];

[@bs.deriving jsConverter]
type orientation = [
  | `default
  | `all
  | `portrait
  | `portrait_up
  | `portrait_down
  | `landscape
  | `landscape_left
  | `landscape_right
];

type headerTitleAlign = [ | `left | `center];

type inputType = [ | `text | `phone | `number | `email];

[@bs.deriving abstract]
type headerSearchBarOptions = {
  [@bs.optional]
  autoCapitalize: TextInput.autoCapitalize,
  [@bs.optional]
  autoFocus: bool,
  [@bs.optional]
  barTintColor: Color.t,
  [@bs.optional]
  cancelButtonText: string,
  [@bs.optional]
  disableBackButtonOverride: bool,
  [@bs.optional]
  hideNavigationBar: bool,
  [@bs.optional]
  hideWhenScrolling: bool,
  [@bs.optional]
  inputType,
  [@bs.optional]
  obscureBackground: bool,
  [@bs.optional]
  placeholder: string,
  [@bs.optional]
  textColor: Color.t,
  [@bs.optional]
  hintTextColor: Color.t,
  [@bs.optional]
  headerIconColor: Color.t,
  [@bs.optional]
  shouldShowHintSearchIcon: bool,
  [@bs.optional]
  onBlur: Event.targetEvent => unit,
  [@bs.optional]
  onCancelButtonPress: Event.pressEvent => unit,
  [@bs.optional]
  onChangeText: string => unit,
};

[@bs.deriving abstract]
type backOptions = {
  [@bs.optional]
  title: string,
};

type gestureDirection = [ | `vertical | `horizontal];

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  headerBackButtonMenuEnabled: bool,
  [@bs.optional]
  headerBackVisible: bool,
  [@bs.optional]
  headerBackTitle: string,
  [@bs.optional]
  headerBackTitleVisible: bool,
  [@bs.optional]
  headerBackTitleStyle,
  [@bs.optional]
  headerBackImageSource: string, // TODO
  [@bs.optional]
  headerLargeStyle,
  [@bs.optional]
  headerLargeTitle: bool,
  [@bs.optional]
  headerLargeTitleShadowVisible: bool,
  [@bs.optional]
  headerLargeTitleStyle,
  [@bs.optional]
  headerShown: bool,
  [@bs.optional]
  headerStyle,
  [@bs.optional]
  headerShadowVisible: bool,
  [@bs.optional]
  headerTransparent: bool,
  [@bs.optional]
  headerBlurEffect: blurEffect,
  [@bs.optional]
  headerBackground: unit => React.element,
  [@bs.optional]
  headerTintColor: Color.t,
  [@bs.optional]
  headerLeft: unit => React.element,
  [@bs.optional]
  headerRight: unit => React.element,
  [@bs.optional]
  headerTitle: string,
  [@bs.optional]
  headerTitleAlign,
  [@bs.optional]
  headerTitleStyle,
  [@bs.optional]
  headerSearchBarOptions,
  /*
   [@bs.optional]
   header: headerParams => React.element,
   */
  [@bs.optional]
  statusBarAnimation,
  [@bs.optional]
  statusBarHidden: bool,
  [@bs.optional]
  statusBarStyle,
  [@bs.optional]
  statusBarColor: Color.t,
  [@bs.optional]
  statusBarTranslucent: bool,
  [@bs.optional]
  contentStyle: Style.t,
  [@bs.optional]
  customAnimationOnGesture: bool,
  [@bs.optional]
  fullScreenGestureEnabled: bool,
  [@bs.optional]
  gestureEnabled: bool,
  [@bs.optional]
  animationTypeForReplace,
  [@bs.optional]
  backButtonInCustomView: bool,
  [@bs.optional]
  animation,
  [@bs.optional]
  presentation,
  [@bs.optional]
  orientation,
  [@bs.optional]
  autoHideHomeIndicator: bool,
  [@bs.optional]
  gestureDirection,
  [@bs.optional]
  animationDuration: float,
  [@bs.optional]
  navigationBarColor: Color.t,
  [@bs.optional]
  navigationBarHidden: bool,
  [@bs.optional]
  freezeOnBlur: bool,
};

// TODO: this was an `and` recursive type, but that doesn't work with deriving abstract
type headerParams = {
  navigation,
  route,
  options,
  back: backOptions,
};

module type NavigatorModule = {
  module Navigator: {
    [@react.component]
    let make:
      (
        ~id: string=?,
        ~initialRouteName: string=?,
        ~screenOptions: screenOptionsParams => options=?,
        ~children: React.element=?
      ) =>
      React.element;
  };

  module Screen: {
    [@react.component]
    let make:
      (
        ~name: string,
        ~navigationKey: string=?,
        ~options: screenOptionsParams => options=?,
        ~initialParams: 'params=?,
        ~getId: getIdOptions=?,
        ~component: React.component(screenProps)=?,
        ~getComponent: unit => React.component(screenProps)=?,
        ~children: screenProps => React.element=?
      ) =>
      React.element;
  };

  module Group: {
    [@react.component]
    let make:
      (
        ~navigationKey: string=?,
        ~screenOptions: screenOptionsParams => options=?
      ) =>
      React.element;
  };
};

type navigatorModule;

[@bs.module "@react-navigation/native-stack"]
external createNativeStackNavigator: unit => navigatorModule =
  "createNativeStackNavigator";

[@bs.module "./Interop"]
external adaptNavigatorModule: navigatorModule => (module NavigatorModule) =
  "adaptNavigatorModule";

module Make = (()) => (
  val createNativeStackNavigator()->adaptNavigatorModule
);

type screenEventData = {closing: int};

module Navigation = {
  [@bs.send] external setOptions: (navigation, options) => unit = "setOptions";

  [@bs.send] external replace: (navigation, string) => unit = "replace";
  [@bs.send]
  external replaceWithParams: (navigation, string, 'params) => unit =
    "replace";

  [@bs.send] external push: (navigation, string) => unit = "push";
  [@bs.send]
  external pushWithParams: (navigation, string, 'params) => unit = "push";

  [@bs.send] external pop: (navigation, ~count: int=?, unit) => unit = "pop";

  [@bs.send] external popToTop: (navigation, unit) => unit = "popToTop";

  [@bs.send]
  external addEventListener:
    (
      navigation,
      [@bs.string] [
        | `transitionStart(navigationEvent(screenEventData) => unit)
        | `transitionEnd(navigationEvent(screenEventData) => unit)
      ]
    ) =>
    unsubscribe =
    "addListener";
};
