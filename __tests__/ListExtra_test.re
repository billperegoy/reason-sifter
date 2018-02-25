open Jest;

describe("find_safe", () => {
  open Expect;

  let list = ["a", "b", "c", "d"];

  test("returns Some result on List.find match", () =>
    expect(ListExtra.find_safe((a) => a == "b", list)) |> toEqual(Some("b"))
  );

  test("returns None on List.find with no match", () =>
    expect(ListExtra.find_safe((a) => a == "e", list)) |> toEqual(None)
  );
});

describe("assoc_safe", () => {
  open Expect;

  let list = [("k1", "v1"), ("k2", "v2")];

  test("returns Some result on List.assoc with match", () =>
    expect(ListExtra.assoc_safe("k2", list)) |> toEqual(Some("v2"))
  );

  test("returns None on List.assoc with no match", () =>
    expect(ListExtra.assoc_safe("k3", list)) |> toEqual(None)
  );
});

describe("assq_safe", () => {
  open Expect;

  let k1 = "k1";
  let k2 = "k2";
  let list = [(k1, "v1"), (k2, "v2")];

  test("returns Some result on List.assoc with match", () =>
    expect(ListExtra.assq_safe(k2, list)) |> toEqual(Some("v2"))
  );

  test("returns None on List.assoc with no match", () =>
    expect(ListExtra.assq_safe("k3", list)) |> toEqual(None)
  );
});
