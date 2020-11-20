# `reason-react-navigation`

[![Build Status](https://github.com/reason-react-native/reason-react-navigation/workflows/Build/badge.svg)](https://github.com/reason-react-native/reason-react-navigation/actions)
[![Version](https://img.shields.io/npm/v/reason-react-navigation.svg)](https://www.npmjs.com/reason-react-navigation)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reasonml-community.github.io/reason-react-native/discord/)

[ReScript](https://rescript-lang.org) / [Reason](https://reasonml.github.io) bindings for
[`react-navigation`](https://github.com/react-navigation/react-navigation).

Exposed as `ReactNavigation` module.

`reason-react-navigation` X.y.\* means it's compatible with `react-navigation`
X.y.\*

## Status

⚠️ Work in progress. These bindings are used successfully in several apps, but
are not complete yet and still subject to change.

## Installation

When
[`react-navigation`](https://github.com/react-navigation/react-navigation) is
properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install reason-react-navigation
# or
yarn add reason-react-navigation
```

`reason-react-navigation` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "reason-react-navigation"
  ],
  //...
}
```

## Example

See <./src/Example.re>

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Contribute

Read the [contribution guidelines](https://github.com/reason-react-native/.github/blob/master/CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/reason-react-native/.github/blob/master/CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.
