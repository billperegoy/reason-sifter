type extractor('a) =
  'a => string;

type conjunctionType =
  | And
  | Or;

type sortOrder =
  | Ascending
  | Descending;

type sortField('a) = {
  field: 'a,
  order: sortOrder
};

type config('a) = {
  extractor: list(extractor('a)),
  limit: int,
  sort: option(sortField('a)),
  filter: bool,
  conjunction: conjunctionType,
  respectWordBoundaries: bool
};

type scoredResult('a) =
  (float, 'a);


let extractResults = (results: list(scoredResult('a))) : list('a) =>
  List.map(snd, results);

let limitResults = (limit: int, results: list(scoredResult('a))) : list(scoredResult('a)) =>
  if (List.length(results) <= limit) {
    results
  } else {
    results
  };


let scores = [(1.0, "a"), (2.0, "b"), (3.0, "c"), (4.0, "d")];
let answers = extractResults(scores);
Js.log(scores);
Js.log(answers);
