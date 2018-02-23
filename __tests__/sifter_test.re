open Jest;

describe("extractResults", () => {
  open Expect;
  open! Expect.Operators;

  let scores = [(1.0, "a"), (2.0, "b"), (3.0, "c"), (4.0, "d")];

  test("extracts object from score tuple", () =>
    expect(Sifter.extractResults(scores)) == ["a", "b", "c", "d"]
  );
});

describe("limitResults", () => {
  open Expect;
  open! Expect.Operators;

  let scores = [(1.0, "a"), (2.0, "b"), (3.0, "c"), (4.0, "d")];

  test("returns whole list if limit == list length", () =>
    expect(Sifter.limitResults(4, scores)) == scores
  );

  test("returns whole list if limit > list length", () =>
    expect(Sifter.limitResults(5, scores)) == scores
  );

  test("returns front of list if limit < list length", () =>
    expect(Sifter.limitResults(2, scores)) ==  [(1.0, "a"), (2.0, "b")]
  );
});
