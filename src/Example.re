// Uncomment this to compile this example outside of this repo
// in this example it's not necessary (since we are running it in the module repo itself)
//open ReactNavigation;
/*
 open ReactNative;

 module HomeScreen = {
   //[@react.component(: Core.screenProps)]
   [@react.component]
   let make = (~navigation as _, ~route as _) =>
     <Text> "Hello Reasonable Person!"->React.string </Text>;
 };

 module ModalScreen = {
   //[@react.component(: Core.screenProps)]
   [@react.component]
   let make = (~navigation as _, ~route as _) =>
     <Text> "Hello From Modal"->React.string </Text>;
 };

 module MainStackScreen = {
   include Stack.Make({});

   //[@react.component(: Core.screenProps)]
   [@react.component]
   let make = (~navigation as _, ~route as _) =>
     <Navigator>
       <Screen
         name="Home"
         component=HomeScreen.make
         options={props =>
           {
             headerRight: _ =>
               <Button
                 onPress={_ =>
                   props.navigation->Core.Navigation.navigate("MyModal")
                 }
                 title="Info"
                 color="#f00"
               />,
             title:
               switch (props.route.params) {
               | Some(params) => params->Core.Params.unsafeGetValue["name"]
               | None => "Reason"
               },
           }
         }
       />
     </Navigator>;
 };

 module RootStackScreen = {
   include Stack.Make({});

   [@react.component]
   let make = () =>
     <Native.NavigationContainer>
       <Navigator screenOptions={_ => {presentation: `modal}}>
         <Screen name="Main" component=MainStackScreen.make />
         <Screen name="MyModal">
           {({navigation, route}) => <ModalScreen navigation route />}
         </Screen>
       </Navigator>
     </Native.NavigationContainer>;
 };
 */
