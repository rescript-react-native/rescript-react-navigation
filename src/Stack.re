open Core;

type options;

type layout = {
  width: float,
  height: float,
};

type layouts = {
  screen: layout,
  title: option(layout),
  leftLabel: option(layout),
};

//TODO
type any;
type animatedNode = ReactNative.Animated.Value.t;
type stackHeaderInterpolation = {progress: animatedNode};
type stackHeaderInterpolationProps = {
  current: stackHeaderInterpolation,
  next: option(stackHeaderInterpolation),
  layouts,
};
type stackHeaderInterpolatedStyle = {
  leftLabelStyle: option(any),
  leftButtonStyle: option(any),
  rightButtonStyle: option(any),
  titleStyle: option(any),
  backgroundStyle: option(any),
};
type stackHeaderStyleInterpolator =
  stackHeaderInterpolationProps => stackHeaderInterpolatedStyle;

type insets = {
  top: float,
  right: float,
  bottom: float,
  left: float,
};

type stackCardInterpolationProps = {
  current: stackHeaderInterpolation,
  next: option(stackHeaderInterpolation),
  index: int,
  closing: animatedNode,
  layouts,
  insets,
};
type stackCardInterpolatedStyle = {
  containerStyle: option(any),
  cardStyle: option(any),
  overlayStyle: option(any),
  shadowStyle: option(any),
};
type stackCardStyleInterpolator =
  stackCardInterpolationProps => stackCardInterpolatedStyle;

type layoutChangeEvent;

type backImageProps = {tintColor: ReactNative.Color.t};
type backImage = backImageProps => React.element;
type stackHeaderLeftButtonProps = {
  disabled: option(bool),
  onPress: option(unit => unit),
  pressColorAndroid: option(ReactNative.Color.t),
  backImage: option(backImage),
  tintColor: option(ReactNative.Color.t),
  label: option(string),
  truncatedLabel: option(string),
  labelVisible: option(bool),
  labelStyle: option(ReactNative.Style.t),
  allowFontScaling: option(bool),
  onLabelLayout: option(layoutChangeEvent => unit),
  screenLayout: option(layout),
  titleLayout: option(layout),
  canGoBack: option(bool),
};

module TransitionSpec = {
  type t;
  type springConfig = {
    damping: int,
    mass: int,
    stiffness: int,
    restSpeedThreshold: int,
    restDisplacementThreshold: int,
    overshootClamping: bool,
  };
  [@bs.obj]
  external spring:
    (~animation: [@bs.string] [ | `spring], ~config: springConfig) => t;

  type timingConfig = {
    duration: int,
    easing: ReactNative.Easing.t,
  };

  [@bs.obj]
  external timing:
    (~animation: [@bs.string] [ | `timing], ~config: timingConfig) => t;
};

type transitionSpec = {
  [@bs.as "open"]
  open_: TransitionSpec.t,
  close: TransitionSpec.t,
};

module StackNavigationScreenProp = (M: {
                                      type params;
                                      type options;
                                    }) => {
  include NavigationScreenProp(M);

  type t = navigation;

  [@bs.send] external push: (t, string) => unit = "push";
  [@bs.send] external pushWithParams: (t, string, M.params) => unit = "push";

  [@bs.send] external pop: (t, ~count: int=?, unit) => unit = "pop";

  [@bs.send] external popToTop: (t, unit) => unit = "popToTop";
};

module Make = (M: {type params;}) => {
  type nonrec route = route(M.params);
  module Navigation =
    StackNavigationScreenProp({
      include M;
      type nonrec options = options;
    });

  type gestureResponseDistance;
  [@bs.obj]
  external gestureResponseDistance:
    (~vertical: float=?, ~horizontal: float=?, unit) => gestureResponseDistance;

  module HeaderTitle = {
    type t;

    type headerTitleProps = {
      onLayout: layoutChangeEvent => unit,
      allowFontScaling: option(bool),
      style: option(ReactNative.Style.t), //textStyle
      children: option(string),
    };

    [@bs.val] [@bs.module "./Interop"]
    external t:
      (
      [@bs.unwrap]
      [ | `String(string) | `Render(headerTitleProps => React.element)]
      ) =>
      t =
      "identity";

    let string = s => t(`String(s));
    let render = x => t(`Render(x));
  };

  type mode = string; //TODO: [ | `float | `screen | `none]

  module Header = {
    type descriptor = {
      render: unit => React.element,
      options,
      navigation,
    };
    type progress = {
      current: animatedNode,
      next: option(animatedNode),
      previous: option(animatedNode),
    };
    type headerProps('params) = {
      mode,
      style: ReactNative.Style.t,
      /* extends NavigationSceneRendererProps */
      layout,
      scene: scene(Core.route('params)),
      previous: option(scene(Core.route('params))),
      navigation,
      styleInterpolator: stackHeaderStyleInterpolator,
    }
    and scene('t) = {
      route: 't,
      descriptor,
      progress,
    };

    type t;
    [@bs.val] [@bs.module "./Interop"]
    external t:
      (
      [@bs.unwrap]
      [
        | `Render(headerProps('params) => React.element)
        | `Null(Js.null(unit))
      ]
      ) =>
      t =
      "identity";

    let render = x => t(`Render(x));

    let null = t(`Null(Js.Null.empty));
  };

  type headerRightOptions = {tintColor: option(ReactNative.Color.t)};

  [@bs.obj]
  external options:
    (
      ~title: string=?,
      ~header: Header.t=?,
      ~cardShadowEnabled: bool=?,
      ~cardOverlayEnabled: bool=?,
      ~cardTransparent: bool=?,
      ~cardStyle: ReactNative.Style.t=?,
      ~animationEnabled: bool=?,
      ~gestureEnabled: bool=?,
      ~gestureResponseDistance: gestureResponseDistance=?,
      // StackHeaderOptions
      ~headerShown: bool=?,
      ~headerTitle: HeaderTitle.t=?,
      ~headerTitleStyle: ReactNative.Style.t=?,
      ~headerTitleContainerStyle: ReactNative.Style.t=?,
      ~headerTintColor: ReactNative.Color.t=?,
      ~headerTitleAllowFontScaling: bool=?,
      ~headerBackAllowFontScaling: bool=?,
      ~headerBackTitle: string=?,
      ~headerBackTitleStyle: ReactNative.Style.t=?,
      ~headerBackTitleVisible: bool=?,
      ~headerTruncatedBackTitle: string=?,
      ~headerLeft: stackHeaderLeftButtonProps => React.element=?,
      ~headerLeftContainerStyle: ReactNative.Style.t=?,
      ~headerRight: headerRightOptions => React.element=?,
      ~headerRightContainerStyle: ReactNative.Style.t=?,
      ~headerBackImage: backImage=?,
      ~headerPressColorAndroid: ReactNative.Color.t=?,
      ~headerBackground: unit => React.element=?,
      ~headerStyle: ReactNative.Style.t=?,
      ~headerTransparent: bool=?,
      // TransitionPreset
      ~gestureDirection: [@bs.string] [ | `horizontal | `vertical]=?,
      ~transitionSpec: transitionSpec=?,
      ~cardStyleInterpolator: stackCardStyleInterpolator=?,
      ~headerStyleInterpolator: stackHeaderStyleInterpolator=?,
      unit
    ) =>
    options;
  type optionsProps = {
    navigation,
    route,
  };
  type optionCallback = optionsProps => options;

  type navigatorProps = {
    initialRouteName: option(string),
    screenOptions: option(optionCallback),
    mode: option(string),
    headerMode: option(string),
    keyboardHandlingEnabled: option(bool),
  };

  type screenProps('params) = {
    name: string,
    options: option(optionCallback),
    initialParams: option('params),
    component:
      React.component({
        .
        "navigation": navigation,
        "route": route,
      }),
  };

  [@bs.module "@react-navigation/stack"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps(M.params) => React.element,
    } =
    "createStackNavigator";

  let stack = make();

  module Screen = {
    type componentProps = {navigation};
    type renderCallbackProp = {
      navigation,
      route,
    };
    type componentOrRenderCallback =
      | Component(
          React.component({
            .
            "navigation": navigation,
            "route": route,
          }),
        )
      | RenderCallback(renderCallbackProp => React.element);
    [@bs.obj]
    external makeProps':
      (
        ~name: string,
        ~options: optionCallback=?,
        ~initialParams: M.params=?,
        ~component: React.component({
                      .
                      "navigation": navigation,
                      "route": route,
                    })
                      =?,
        ~children: renderCallbackProp => React.element=?,
        unit
      ) =>
      screenProps(M.params);
    let makeProps =
        (
          ~name,
          ~options=?,
          ~initialParams=?,
          ~componentOrRenderCallback: componentOrRenderCallback,
          (),
        ) => {
      switch (componentOrRenderCallback) {
      | Component(component) =>
        let makeProps' = makeProps'(~name, ~component);
        switch (options, initialParams) {
        | (None, None) => makeProps'()
        | (Some(options), None) => makeProps'(~options, ())
        | (None, Some(initialParams)) => makeProps'(~initialParams, ())
        | (Some(options), Some(initialParams)) =>
          makeProps'(~options, ~initialParams, ())
        };
      | RenderCallback(children) =>
        let makeProps' = makeProps'(~name, ~children);
        switch (options, initialParams) {
        | (None, None) => makeProps'()
        | (Some(options), None) => makeProps'(~options, ())
        | (None, Some(initialParams)) => makeProps'(~initialParams, ())
        | (Some(options), Some(initialParams)) =>
          makeProps'(~options, ~initialParams, ())
        };
      };
    };
    let make = stack##"Screen";
  };

  module Navigator = {
    [@bs.obj]
    external makeProps:
      (
        ~initialRouteName: string=?,
        ~screenOptions: optionCallback=?,
        ~mode: [@bs.string] [ | `card | `modal]=?,
        ~headerMode: [@bs.string] [ | `float | `screen | `none]=?,
        ~keyboardHandlingEnabled: bool=?,
        ~children: React.element,
        unit
      ) =>
      navigatorProps;

    let make = stack##"Navigator";
  };
};

module TransitionSpecs = {
  /* Exact values from UINavigationController's animation configuration */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external transitionIOSSpec: transitionSpec = "TransitionIOSSpec";
  /* Configuration for activity open animation from Android Nougat */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external fadeInFromBottomAndroidSpec: transitionSpec =
    "FadeInFromBottomAndroidSpec";
  /* Configuration for activity close animation from Android Nougat */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external fadeOutToBottomAndroidSpec: transitionSpec =
    "FadeOutToBottomAndroidSpec";
  /* Approximate configuration for activity open animation from Android Pie */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external revealFromBottomAndroidSpec: transitionSpec =
    "RevealFromBottomAndroidSpec";
};

module CardStyleInterpolators = {
  /* Standard iOS-style slide in from the right */
  [@bs.module "@react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forHorizontalIOS: stackCardStyleInterpolator = "forHorizontalIOS";
  /* Standard iOS-style slide in from the bottom (used for modals) */
  [@bs.module "@react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forVerticalIOS: stackCardStyleInterpolator = "forVerticalIOS";
  /* Standard iOS-style modal animation in iOS 13 */
  [@bs.module "@react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forModalPresentationIOS: stackCardStyleInterpolator =
    "forModalPresentationIOS";
  /* Standard Android-style fade in from the bottom for Android Oreo */
  [@bs.module "@react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forFadeFromBottomAndroid: stackCardStyleInterpolator =
    "forFadeFromBottomAndroid";
  /* Standard Android-style reveal from the bottom for Android Pie */
  [@bs.module "@react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forRevealFromBottomAndroid: stackCardStyleInterpolator =
    "forRevealFromBottomAndroid";
};

module HeaderStyleInterpolators = {
  /* Standard UIKit style animation for the header where the title fades into the back button label */
  [@bs.module "@react-navigation/stack"] [@bs.scope "HeaderStyleInterpolators"]
  external forUIKit: stackHeaderStyleInterpolator = "forUIKit";
  /* Simple fade animation for the header elements */
  [@bs.module "@react-navigation/stack"] [@bs.scope "HeaderStyleInterpolators"]
  external forFade: stackHeaderStyleInterpolator = "forFade";
  /* Simple translate animation to translate the header along with the sliding screen */
  [@bs.module "@react-navigation/stack"] [@bs.scope "HeaderStyleInterpolators"]
  external forStatic: stackHeaderStyleInterpolator = "forStatic";
};

module TransitionPresets = {
  /* Standard iOS navigation transition. */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external slideFromRightIOS: options = "SlideFromRightIOS";

  /* Standard iOS navigation transition for modals. */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external modalSlideFromBottomIOS: options = "ModalSlideFromBottomIOS";

  /* Standard iOS modal presentation style (introduced in iOS 13). */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external modalPresentationIOS: options = "ModalPresentationIOS";

  /* Standard Android navigation transition when opening or closing an Activity on Android < 9 (Oreo). */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external fadeFromBottomAndroid: options = "FadeFromBottomAndroid";

  /* Standard Android navigation transition when opening or closing an Activity on Android >= 9 (Pie). */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external revealFromBottomAndroid: options = "RevealFromBottomAndroid";

  /* Default navigation transition for the current platform. */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external defaultTransition: options = "DefaultTransition";

  /* Default modal transition for the current platform. */
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external modalTransition: options = "ModalTransition";
};

[@bs.val]
external mergeOptions: (options, options) => options = "Object.assign";
