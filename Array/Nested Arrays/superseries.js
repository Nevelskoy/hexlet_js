const getSuperSeriesWinner = (match) => {

  let ussr = 0;
  let canada = 0;
  for (const scores of match) {
    if (scores[0] > scores[1]) {
      canada += 1;
    } else if (scores[0] < scores[1]) {
       ussr += 1;
    }
  }
  if (ussr === canada) {
    return null;
  }
  return (ussr > canada) ? 'ussr' : 'canada';
};
export default getSuperSeriesWinner;
