open Jest;
type person = {name: string};

describe("extractResults", () => {
  open Expect;
  open! Expect.Operators;

  let scores = [(1.0, "a"), (2.0, "b"), (3.0, "c"), (4.0, "d")];

  test("extracts object from score tuple", () =>
    expect(Sifter.extract_results(scores)) == ["a", "b", "c", "d"]
  );
});

describe("limitResults", () => {
  open Expect;
  open! Expect.Operators;

  let scores = [(1.0, "a"), (2.0, "b"), (3.0, "c"), (4.0, "d")];

  test("returns whole list if limit == list length", () =>
    expect(Sifter.limit_results(4, scores)) == scores
  );

  test("returns whole list if limit > list length", () =>
    expect(Sifter.limit_results(5, scores)) == scores
  );

  test("returns front of list if limit < list length", () =>
    expect(Sifter.limit_results(2, scores)) ==  [(1.0, "a"), (2.0, "b")]
  );
});

describe("match_one", () => {
  open Expect;
  open! Expect.Operators;

  let joe = {name: "Joe"};
  let name_extractor = (person) => person.name;

  test("returns score of 0.0 if no match", () =>
    expect(Sifter.match_one(name_extractor, "Fred", joe)) == (0.0, joe)
  );

  test("returns score of 1.5 if exact match from the beginning", () =>
    expect(Sifter.match_one(name_extractor, "oe", joe)) == (1.5, joe)
  );
});
