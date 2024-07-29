# Tree Sitter Jai

## Limitations

This grammar cannot differentiate between passing the address of a variable or passing a pointer type.
For example `proc(*Vector3)` could either mean a pointer to a variable called Vector3 or a type that is a pointer to a `Vector3`.
This grammar considers those a allways begin the "address" operator.

## Getting Started

- Install [Node.js](https://nodejs.org) and [pnpm](https://pnpm.io/)
- Run `pnpm i`

You should now be able to run tests using pnpm run test.