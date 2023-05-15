// Port of https://github.com/rescript-react-native/rescript-react-navigation/blob/main/src/Example.res

// Uncomment this to compile this example outside of this repo
// in this example it's not necessary (since we are running it in the module repo itself)

// open ReactNavigation;
open ReactNative;

module Screens = {
  type t = {
    name: string,
    title: string,
  };

  let main = {name: "Main", title: "Main"};
  let home = {name: "Home", title: "Home"};
  let todo = {name: "TODO", title: "TODO List"};
  let modal = {name: "Modal", title: "Modal"};
};

type todoParams = {items: list(string)};

module Home = {
  [@react.component]
  let make = (~navigation, ~route: Core.route) => {
    Js.log(route);
    Js.log(route.params);

    <>
      <Text> "Home Page"->React.string </Text>
      <Button
        onPress={_ =>
          navigation->Core.Navigation.navigateWithParams(
            Screens.todo.name,
            {items: ["this", "that"]},
          )
        }
        title={Screens.todo.title}
      />
    </>;
  };
};

module TODOList = {
  [@react.component]
  let make = (~navigation, ~route: Core.route) => {
    Js.log(route);
    Js.log(route.params);

    let items: list(string) =
      switch (route.params) {
      | Some(params) => params->Core.Params.asJs##items
      | None => []
      };

    <>
      <Text> "My TODO List"->React.string </Text>
      {React.array(
         items
         ->Belt.List.map(item => <Text key=item> item->React.string </Text>)
         ->Belt.List.toArray,
       )}
      <Button
        onPress={_ => navigation->Core.Navigation.goBack()}
        title="Go Back"
      />
    </>;
  };
};

module Modal = {
  [@react.component]
  let make = (~navigation as _, ~route as _) =>
    <Text> "My Modal"->React.string </Text>;
};

module MainStackScreen = {
  include Stack.Make({});

  [@react.component]
  let make = (~navigation as _, ~route as _) =>
    <Navigator>
      <Screen
        name={Screens.home.name}
        component=Home.make
        options={props =>
          Stack.options(
            ~title=
              switch (props.route.params) {
              // TODO: this wanted int rather than string
              // | Some(params) => params->Core.Params.unsafeGetValue["name"]
              | Some(params) => params->Core.Params.unsafeGetValue[0]
              | None => "Reason"
              },
            ~headerRight=
              _ =>
                <Button
                  onPress={_ =>
                    props.navigation
                    ->Core.Navigation.navigate(Screens.modal.name)
                  }
                  title={Screens.modal.title}
                />,
            (),
          )
        }
      />
      <Screen
        name={Screens.todo.name}
        component=TODOList.make
        options={_ =>
          Stack.options(
            ~title={
              Screens.todo.title;
            },
            (),
          )
        }
      />
    </Navigator>;
};

module RootStackScreen = {
  include Stack.Make({});

  [@react.component]
  let make = () =>
    <Native.NavigationContainer>
      <Navigator screenOptions={_ => Stack.options(~presentation=`modal, ())}>
        <Screen name={Screens.main.name} component=MainStackScreen.make />
        <Screen name={Screens.modal.name}> Modal.make </Screen>
      </Navigator>
    </Native.NavigationContainer>;
};

[@react.component]
let app = () => <> <RootStackScreen /> </>;

/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * Converted from https://github.com/facebook/react-native/blob/724fe11472cb874ce89657b2c3e7842feff04205/template/App.js
 * With a few tweaks
 */;

/*
 open ReactNative;

 type reactNativeNewAppScreenColors = {
   .
   "primary": string,
   "white": string,
   "lighter": string,
   "light": string,
   "black": string,
   "dark": string,
 };

 [@bs.module "react-native/Libraries/NewAppScreen"]
 external colors: reactNativeNewAppScreenColors = "Colors";

 [@bs.module "react-native/Libraries/Core/Devtools/openURLInBrowser"]
 external openURLInBrowser: string => unit = "default";

 module Header = {
   [@react.component] [@bs.module "react-native/Libraries/NewAppScreen"]
   external make: _ => React.element = "Header";
 };
 module ReloadInstructions = {
   [@react.component] [@bs.module "react-native/Libraries/NewAppScreen"]
   external make: _ => React.element = "ReloadInstructions";
 };
 module LearnMoreLinks = {
   [@react.component] [@bs.module "react-native/Libraries/NewAppScreen"]
   external make: _ => React.element = "LearnMoreLinks";
 };
 module DebugInstructions = {
   [@react.component] [@bs.module "react-native/Libraries/NewAppScreen"]
   external make: _ => React.element = "DebugInstructions";
 };

 /*
  Here is StyleSheet that is using Style module to define styles for your components
  The main different with JavaScript components you may encounter in React Native
  is the fact that they **must** be defined before being referenced
  (so before actual component definitions)
  More at https://reason-react-native.github.io/en/docs/apis/Style/
  */
 let styles =
   Style.(
     StyleSheet.create({
       "scrollView": style(~backgroundColor=colors##lighter, ()),
       "engine": style(~position=`absolute, ~right=0.->dp, ()),
       "body": style(~backgroundColor=colors##white, ()),
       "sectionContainer":
         style(~marginTop=32.->dp, ~paddingHorizontal=24.->dp, ()),
       "sectionTitle":
         style(~fontSize=24., ~fontWeight=`_600, ~color=colors##black, ()),
       "sectionDescription":
         style(
           ~marginTop=8.->dp,
           ~fontSize=18.,
           ~fontWeight=`_400,
           ~color=colors##dark,
           (),
         ),
       "highlight": style(~fontWeight=`_700, ()),
       "footer":
         style(
           ~color=colors##dark,
           ~fontSize=12.,
           ~fontWeight=`_600,
           ~padding=4.->dp,
           ~paddingRight=12.->dp,
           ~textAlign=`right,
           (),
         ),
     })
   );

 [@react.component]
 let app = () =>
   <>
     <StatusBar barStyle=`darkContent />
     <SafeAreaView>
       <ScrollView
         contentInsetAdjustmentBehavior=`automatic style={styles##scrollView}>
         {Global.hermesInternal->Belt.Option.isNone
            ? React.null
            : <View style=styles##engine>
                <Text style=styles##footer>
                  "Engine: Hermes"->React.string
                </Text>
              </View>}
         <Header />
         <View style={styles##body}>
           <View style={styles##sectionContainer}>
             <Text style={styles##sectionTitle}>
               "Step One"->React.string
             </Text>
             <Text style={styles##sectionDescription}>
               "Edit "->React.string
               <Text style={styles##highlight}>
                 "src/App.re"->React.string
               </Text>
               " to change this screen and then come back to see your edits."
               ->React.string
             </Text>
           </View>
           <View style={styles##sectionContainer}>
             <Text style={styles##sectionTitle}>
               "See Your Changes"->React.string
             </Text>
             <Text style={styles##sectionDescription}>
               <ReloadInstructions />
             </Text>
           </View>
           <View style={styles##sectionContainer}>
             <Text style={styles##sectionTitle}> "Debug"->React.string </Text>
             <Text style={styles##sectionDescription}>
               <DebugInstructions />
             </Text>
           </View>
           <View style={styles##sectionContainer}>
             <Text style={styles##sectionTitle}>
               "Learn More"->React.string
             </Text>
             <Text style={styles##sectionDescription}>
               "Read the docs to discover what to do next:"->React.string
             </Text>
           </View>
           <View style={styles##sectionContainer}>
             <Text style={styles##sectionDescription}>
               <Text style={styles##highlight}>
                 "Reason React Native"->React.string
               </Text>
             </Text>
             <TouchableOpacity
               onPress={_ =>
                 openURLInBrowser(
                   "https://reason-react-native.github.io/en/docs/",
                 )
               }>
               <Text
                 style=Style.(
                   style(
                     ~marginTop=8.->dp,
                     ~fontSize=18.,
                     ~fontWeight=`_400,
                     ~color=colors##primary,
                     (),
                   )
                 )>
                 "https://reason-react-native.github.io/"->React.string
               </Text>
             </TouchableOpacity>
           </View>
           <View style={styles##sectionContainer}>
             <Text style={styles##sectionDescription}>
               <Text style={styles##highlight}>
                 "React Native"->React.string
               </Text>
             </Text>
           </View>
           <LearnMoreLinks />
         </View>
       </ScrollView>
     </SafeAreaView>
   </>;
   */
