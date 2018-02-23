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

let extractResults = (results: scoredResultList('a)) : list('a) =>
  List.map(snd, results);

let rec takeReversed = (limit: int , results: scoredResultList('a)) : scoredResultList('a) =>
  switch(results) {
  | [] => []
  | [_head, ...tail] =>
       if (List.length(results) == limit) {
         List.rev(results)
       } else {
         takeReversed(limit, tail)
       };
  };

let limitResults = (limit: int, results: scoredResultList('a)) : scoredResultList('a) =>
  if (List.length(results) <= limit) {
    results
  } else {
    results
    |> List.rev
    |> takeReversed(limit)
  };

