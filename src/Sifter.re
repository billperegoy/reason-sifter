type extractor('a) =
  'a => string;

type extractorList('a) =
  list(extractor('a));

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
  extractor: extractorList('a),
  limit: int,
  sort: option(sortField('a)),
  filter: bool,
  conjunction: conjunctionType,
  respectWordBoundaries: bool
};

type scoredResult('a) =
  (float, 'a);

type scoredResultList('a) =
  list(scoredResult('a));

let extract_results = (results: scoredResultList('a)) : list('a) =>
  List.map(snd, results);

let rec take_reversed = (limit: int , results: scoredResultList('a)) : scoredResultList('a) =>
  switch(results) {
  | [] => []
  | [_head, ...tail] =>
       if (List.length(results) == limit) {
         List.rev(results)
       } else {
         take_reversed(limit, tail)
       };
  };

let limit_results = (limit: int, results: scoredResultList('a)) : scoredResultList('a) =>
  if (List.length(results) <= limit) {
    results
  } else {
    results
    |> List.rev
    |> take_reversed(limit)
  };

let match_one = (extractor: extractor('a), string: string, elem: 'a) : scoredResult('a) =>
  (0.0, elem)

/* https://bucklescript.github.io/bucklescript/api/Js.Re.html */
/*
  Js.Re.fromString(string)
  |> Js.Re.exec(extractor(elem))
  |> function
    | Some(result) => (0.0, elem)
    | None => (0.0, elem)
*/
