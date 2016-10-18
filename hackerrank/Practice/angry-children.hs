import Data.List

data TestCase = TestCase Integer [Integer]

readTestCase :: [Integer] -> TestCase
readTestCase (x:xs) = TestCase x xs

solve :: TestCase -> Integer
solve (TestCase k xs) = minimum $ map (\(a,b) -> b - a) $ zip sxs (drop (fromIntegral (k - 1)) sxs) where
	sxs = sort xs

main :: IO ()
main = getContents >>= print . solve . readTestCase . map (read :: String -> Integer) . tail . words
