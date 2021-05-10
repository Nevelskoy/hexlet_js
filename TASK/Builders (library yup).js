const getInvalidBooks = (books) => {
  const schema = yup.object().shape({
    name: yup.string().required(),
    author: yup.string().required(),
    pagesCount: yup.number(),
    link: yup.string().min(1).url(),
    genre: yup.string().oneOf(genres),
  });
 
  return books.filter((book) => !schema.isValidSync(book));
};
