open Jest;

describe("Expect", () => {
  open Expect;

  test("toBe", () =>
    expect(1 + 2) |> toBe(3))
});

describe("Expect.Operators", () => {
  open Expect;
  open! Expect.Operators;

  test("==", () =>
    expect(1 + 2) === 3)
  }
);


describe("extractResults", () => {
  open Expect;
  open! Expect.Operators;

  let scores = [(1.0, "a"), (2.0, "b"), (3.0, "c"), (4.0, "d")];

  test("extracts object from score tuple", () =>
    expect(Sifter.extractResults(scores)) == ["a", "b", "c", "d"]
  )
});
