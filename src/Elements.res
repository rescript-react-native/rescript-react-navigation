open ReactNative

module Header = {
  type headerTitleProps = {
    allowFontScaling: option<bool>,
    tintColor: option<Color.t>,
    style: option<Style.t>,
    children: string,
  }

  @unboxed
  type headerTitle =
    | String(string)
    | Function(headerTitleProps => React.element)

  type displayMode = [#default | #generic | #minimal]

  type headerRightProps = {
    tintColor: option<Color.t>,
    pressColor: option<Color.t>,
    pressOpacity: option<float>,
    canGoBack: option<bool>,
  }
  type headerLeftProps = {
    ...headerRightProps,
    displayMode: option<displayMode>,
    href: option<string>,
  }

  type headerBackgroundOptions = {style: option<Style.t>}

  type headerTitleAlign = [#left | #center]

  type inputType = [
    | #text
    | #phone
    | #number
    | #email
  ]

  type headerSearchBarOptions = {
    ref?: TextInputElement.ref,
    autoCapitalize?: TextInput.autoCapitalize,
    autoFocus?: bool,
    cancelButtonText?: string,
    inputType?: inputType,
    onBlur?: Event.targetEvent => unit,
    onChangeText?: string => unit,
    onClose?: unit => unit,
    onFocus?: Event.targetEvent => unit,
    placeholder?: string,
  }

  type headerCommonOptions = {
    headerTitle?: headerTitle,
    headerTitleAlign?: headerTitleAlign,
    headerLeft?: headerLeftProps => React.element,
    headerRight?: headerRightProps => React.element,
    headerTintColor?: Color.t,
    headerBackground?: headerBackgroundOptions => React.element,
    headerTransparent?: bool,
    headerShadowVisible?: bool,
  }

  type headerOptions = {
    ...headerCommonOptions,
    headerTitleStyle?: Style.t,
    headerTitleAllowFontScaling?: bool,
    headerTitleContainerStyle?: Style.t,
    headerLeftContainerStyle?: Style.t,
    headerRightContainerStyle?: Style.t,
    headerSearchBarOptions?: headerSearchBarOptions,
    headerPressColor?: Color.t,
    headerPressOpacity?: float,
    headerBackgroundContainerStyle?: Style.t,
    headerStyle?: Style.t,
    headerStatusBarHeight?: Style.size,
  }

  type backProp = {
    title?: string,
    href?: string,
  }

  type props = {
    ...headerOptions,
    backProp?: backProp,
    modal?: bool,
    layout?: Core.layout,
    title: string,
  }

  @module("@react-navigation/elements")
  external make: React.component<props> = "Header"
}

module HeaderBackground = {
  @module("@react-navigation/elements")
  external make: React.component<View.props> = "HeaderBackground"
}

module HeaderTitle = {
  @module("@react-navigation/elements")
  external make: React.component<Text.props> = "HeaderTitle"
}

module HeaderButton = {
  type headerButtonProps = {
    tintColor?: Color.t,
    pressColor?: Color.t,
    pressOpacity?: float,
    onPress?: unit => unit,
    href?: string,
    disabled?: bool,
    accessibilityLabel?: string,
    testID?: string,
    style?: Style.t,
  }

  type props = {
    ...headerButtonProps,
    children: React.element,
  }

  @module("@react-navigation/elements")
  external make: React.component<props> = "HeaderTitle"
}

module HeaderBackButton = {
  type backImageProps = {tintColor?: Color.t}

  type props = {
    ...HeaderButton.headerButtonProps,
    backImage?: backImageProps => React.element,
    label?: string,
    truncatedLabel?: string,
    displayMode?: Header.displayMode,
    labelStyle?: Style.t,
    allowFontScaling?: bool,
    onLabelLayout?: Event.layoutEvent => unit,
    screenLayout?: Core.layout,
    titleLayout?: Core.layout,
  }

  @module("@react-navigation/elements")
  external make: React.component<props> = "HeaderBackButton"
}

@module("@react-navigation/elements")
external useHeaderHeight: unit => float = "useHeaderHeight"
