open Jest;

describe("index", () => {
  open Expect;

  let str = "hello";

  test("returns Some result on String.index with match", () =>
    expect(StringExtra.index_safe(str, 'e')) |> toEqual(Some(1))
  );

  test("returns None on String.index with no match", () =>
    expect(StringExtra.index_safe(str, 'x')) |> toEqual(None)
  );
});

describe("rindex", () => {
  open Expect;

  let str = "hello";

  test("returns Some result on String.index with match", () =>
    expect(StringExtra.rindex_safe(str, 'l')) |> toEqual(Some(3))
  );

  test("returns None on String.index with no match", () =>
    expect(StringExtra.rindex_safe(str, 'x')) |> toEqual(None)
  );
});

describe("index_from", () => {
  open Expect;

  let str = "hello";

  test("returns Some result on String.index_from with match", () =>
    expect(StringExtra.index_from(str, 1, 'e')) |> toEqual(Some(1))
  );

  test("returns None on String.index_from with no match", () =>
    expect(StringExtra.index_from(str, 4, 'e')) |> toEqual(None)
  );
});

describe("rindex_from", () => {
  open Expect;

  let str = "hello";

  test("returns Some result on String.rindex_from with match", () =>
    expect(StringExtra.rindex_from(str, 1, 'h')) |> toEqual(Some(0))
  );

  test("returns None on String.rindex_from with no match", () =>
    expect(StringExtra.rindex_from(str, 1, 'o')) |> toEqual(None)
  );
});
