// This was a temp file trying to get this to build without the deps installed

/*
 module Animated = {
   module Value = {
     type t;
   };
 };

 module Color = {
   type t;
 };

 module Easing = {
   type t;
 };

 module Event = {
   type pressEvent;
   type targetEvent;
 };

 module Ref = {
   type t('a);
 };

 module Style = {
   type t;
   type size;

   type fontWeight;
 };

 module Text = {
   //[@react.component]
   //external make: () => React.element;
 };

 module TextInput = {
   type autoCapitalize;
 };
 */

/*
 type fontWeight =
   [@bs.string] [
     | `normal
     | `bold
     | [@bs.as "100"] `_100
     | [@bs.as "200"] `_200
     | [@bs.as "300"] `_300
     | [@bs.as "400"] `_400
     | [@bs.as "500"] `_500
     | [@bs.as "600"] `_600
     | [@bs.as "700"] `_700
     | [@bs.as "800"] `_800
     | [@bs.as "900"] `_900
   ];
   */

// Older version of `reason-react-native` doesn't have the fontWeight type
/*
 module FontWeight: {
   type t;
   let normal: t;
   let bold: t;
 } = {
   type t = string;
   let normal = "normal";
   let bold = "bold";
   // TODO: add more
 };
 */

[@bs.deriving jsConverter]
type fontWeight = [
  | `normal
  | `bold
  | [@bs.as "100"] `_100
  | [@bs.as "200"] `_200
  | [@bs.as "300"] `_300
  | [@bs.as "400"] `_400
  | [@bs.as "500"] `_500
  | [@bs.as "600"] `_600
  | [@bs.as "700"] `_700
  | [@bs.as "800"] `_800
  | [@bs.as "900"] `_900
];
